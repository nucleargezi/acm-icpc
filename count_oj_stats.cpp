#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

namespace fs = std::filesystem;

namespace {

std::string ToLower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
      [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
  return s;
}

std::string EscapeJson(const std::string& s) {
  std::ostringstream oss;
  for (unsigned char c : s) {
    switch (c) {
      case '\"': oss << "\\\""; break;
      case '\\': oss << "\\\\"; break;
      case '\b': oss << "\\b"; break;
      case '\f': oss << "\\f"; break;
      case '\n': oss << "\\n"; break;
      case '\r': oss << "\\r"; break;
      case '\t': oss << "\\t"; break;
      default:
        if (c < 0x20) {
          oss << "\\u" << std::hex << std::setw(4) << std::setfill('0')
              << static_cast<int>(c) << std::dec << std::setfill(' ');
        } else {
          oss << static_cast<char>(c);
        }
    }
  }
  return oss.str();
}

std::string FormatLocalTime(std::chrono::system_clock::time_point tp) {
  const std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::tm local_tm {};
#if defined(_WIN32)
  localtime_s(&local_tm, &t);
#else
  localtime_r(&t, &local_tm);
#endif
  std::ostringstream oss;
  oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

std::string FormatLocalDate(std::chrono::system_clock::time_point tp) {
  const std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::tm local_tm {};
#if defined(_WIN32)
  localtime_s(&local_tm, &t);
#else
  localtime_r(&t, &local_tm);
#endif
  std::ostringstream oss;
  oss << std::put_time(&local_tm, "%Y/%m/%d");
  return oss.str();
}

std::string FormatLocalMonth(std::chrono::system_clock::time_point tp) {
  const std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::tm local_tm {};
#if defined(_WIN32)
  localtime_s(&local_tm, &t);
#else
  localtime_r(&t, &local_tm);
#endif
  std::ostringstream oss;
  oss << std::put_time(&local_tm, "%Y/%m");
  return oss.str();
}

bool StartsWith(const std::string& s, const std::string& prefix) {
  return s.size() >= prefix.size() && s.compare(0, prefix.size(), prefix) == 0;
}

bool UpdateSummaryText(const fs::path& path, const std::string& today,
    const std::string& month, std::uint64_t total) {
  std::ifstream ifs(path);
  std::vector<std::string> before;
  if (ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
      before.push_back(line + '\n');
    }
    if (!ifs.good() && !ifs.eof()) {
      std::cerr << "[error] failed while reading summary text: " << path
                << "\n";
      return false;
    }
  }

  const std::string header = "#### Summary (since 2024/12)\n";
  const std::string new_line =
      "- " + today + "   problems: " + std::to_string(total) + ";\n";
  const bool has_month =
      std::any_of(before.begin(), before.end(), [&](const std::string& line) {
        return line.find(month) != std::string::npos;
      });

  std::vector<std::string> out;
  out.push_back(header);

  if (has_month) {
    for (std::size_t i = 1; i < before.size(); ++i) {
      const std::string& line = before[i];
      if (StartsWith(line, "- ") && line.find(month) != std::string::npos) {
        out.push_back(new_line);
      } else if (!line.empty() && line != "\n") {
        out.push_back(line);
      }
    }
  } else {
    out.push_back(new_line);
    for (std::size_t i = 1; i < before.size(); ++i) {
      const std::string& line = before[i];
      if (StartsWith(line, "- ") && line != "\n") {
        out.push_back(line);
      }
    }
  }

  std::ofstream ofs(path);
  if (!ofs) {
    std::cerr << "[error] cannot open summary text file: " << path << "\n";
    return false;
  }
  for (const std::string& line : out) {
    ofs << line;
  }
  if (!ofs.good()) {
    std::cerr << "[error] failed while writing summary text: " << path << "\n";
    return false;
  }
  return true;
}

std::uint64_t CountSolvedFilesInDir(
    const fs::path& dir, const std::set<std::string>& exts) {
  std::uint64_t count = 0;
  std::error_code ec;
  fs::recursive_directory_iterator it(
      dir, fs::directory_options::skip_permission_denied, ec);
  fs::recursive_directory_iterator end;

  if (ec) {
    std::cerr << "[warn] cannot access directory: " << dir << " ("
              << ec.message() << ")\n";
    return 0;
  }

  while (it != end) {
    std::error_code type_ec;
    const fs::directory_entry& entry = *it;
    if (entry.is_regular_file(type_ec)) {
      const std::string ext = ToLower(entry.path().extension().string());
      if (exts.find(ext) != exts.end()) {
        ++count;
      }
    } else if (type_ec) {
      std::cerr << "[warn] cannot inspect entry: " << entry.path() << " ("
                << type_ec.message() << ")\n";
    }

    it.increment(ec);
    if (ec) {
      std::cerr << "[warn] traversal issue under: " << dir << " ("
                << ec.message() << ")\n";
      ec.clear();
    }
  }

  return count;
}

}  // namespace

int main() {
  const fs::path root = fs::current_path();
  const fs::path json_output_path = root / "Z_pack" / "summary.json";
  const fs::path txt_output_path = root / "Z_pack" / "z_txt0";

  const std::set<std::string> target_exts = {
      ".cpp",
      ".py",
      ".rs",
  };
  const std::set<std::string> excluded_top_dirs = {
      ".venv",
      ".vscode",
      "Z_pack",
      ".git",
  };

  std::map<std::string, std::uint64_t> platforms;
  std::uint64_t total = 0;

  std::error_code ec;
  fs::directory_iterator it(
      root, fs::directory_options::skip_permission_denied, ec);
  fs::directory_iterator end;
  if (ec) {
    std::cerr << "[error] cannot list root directory: " << root << " ("
              << ec.message() << ")\n";
    return 1;
  }

  for (; it != end; it.increment(ec)) {
    if (ec) {
      std::cerr << "[warn] top-level traversal issue: " << ec.message() << "\n";
      ec.clear();
      continue;
    }

    std::error_code type_ec;
    if (!it->is_directory(type_ec)) {
      continue;
    }
    if (type_ec) {
      std::cerr << "[warn] cannot inspect top-level entry: " << it->path()
                << " (" << type_ec.message() << ")\n";
      continue;
    }

    const std::string dirname = it->path().filename().string();
    if (excluded_top_dirs.find(dirname) != excluded_top_dirs.end()) {
      continue;
    }

    const std::uint64_t count = CountSolvedFilesInDir(it->path(), target_exts);
    platforms[dirname] = count;
    total += count;
  }

  std::error_code mkdir_ec;
  fs::create_directories(json_output_path.parent_path(), mkdir_ec);
  if (mkdir_ec) {
    std::cerr << "[error] cannot create output directory: "
              << json_output_path.parent_path() << " (" << mkdir_ec.message()
              << ")\n";
    return 1;
  }

  std::ofstream ofs(json_output_path);
  if (!ofs) {
    std::cerr << "[error] cannot open output file: " << json_output_path
              << "\n";
    return 1;
  }

  ofs << "{\n";
  ofs << "  \"updated_at\": \""
      << EscapeJson(FormatLocalTime(std::chrono::system_clock::now()))
      << "\",\n";
  ofs << "  \"root\": \"" << EscapeJson(fs::absolute(root).string()) << "\",\n";
  ofs << "  \"total\": " << total << ",\n";
  ofs << "  \"platforms\": {\n";

  bool first = 1;
  for (const auto& [name, cnt] : platforms) {
    if (not first) {
      ofs << ",\n";
    }
    first = 0;
    ofs << "    \"" << EscapeJson(name) << "\": " << cnt;
  }
  ofs << "\n";
  ofs << "  }\n";
  ofs << "}\n";

  if (not ofs.good()) {
    std::cerr << "[error] failed while writing output file: "
              << json_output_path << "\n";
    return 1;
  }
  ofs.close();

  const auto now = std::chrono::system_clock::now();
  const std::string today = FormatLocalDate(now);
  const std::string month = FormatLocalMonth(now);
  if (!UpdateSummaryText(txt_output_path, today, month, total)) {
    return 1;
  }

  std::cout << "Wrote statistics to: " << json_output_path << "\n";
  std::cout << "Updated summary text: " << txt_output_path << "\n";
  std::cout << "Total solved files: " << total << "\n";
  return 0;
}
