#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace fs = std::filesystem;

namespace {

using std::string;
using ll = long long;

struct PlatformCount {
  string name;
  ll count;
};

class JsonParser {
 public:
  explicit JsonParser(string content) : text_(std::move(content)), pos_(0) {}

  std::vector<PlatformCount> ParsePlatforms() {
    SkipWs();
    Expect('{');
    std::vector<PlatformCount> platforms;
    bool found_platforms = false;

    SkipWs();
    if (Peek('}')) {
      throw Error("top-level JSON object is empty");
    }

    while (true) {
      SkipWs();
      const string key = ParseString();
      SkipWs();
      Expect(':');
      SkipWs();

      if (key == "platforms") {
        platforms = ParsePlatformsObject();
        found_platforms = true;
      } else {
        SkipValue();
      }

      SkipWs();
      if (Match(',')) continue;
      Expect('}');
      break;
    }

    SkipWs();
    if (pos_ != text_.size()) {
      throw Error("unexpected trailing characters");
    }
    if (!found_platforms) {
      throw Error("missing key: platforms");
    }
    if (platforms.empty()) {
      throw Error("platforms object is empty");
    }
    return platforms;
  }

 private:
  std::runtime_error Error(const string& msg) const {
    std::ostringstream oss;
    oss << "JSON parse error at position " << pos_ << ": " << msg;
    return std::runtime_error(oss.str());
  }

  bool Peek(char c) const { return pos_ < text_.size() && text_[pos_] == c; }

  bool Match(char c) {
    if (Peek(c)) {
      ++pos_;
      return true;
    }
    return false;
  }

  void Expect(char c) {
    if (!Match(c)) {
      std::ostringstream oss;
      oss << "expected '" << c << "'";
      throw Error(oss.str());
    }
  }

  void SkipWs() {
    while (pos_ < text_.size()) {
      const char c = text_[pos_];
      if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
        ++pos_;
      } else {
        break;
      }
    }
  }

  string ParseString() {
    Expect('"');
    string out;
    while (pos_ < text_.size()) {
      char c = text_[pos_++];
      if (c == '"') {
        return out;
      }
      if (c == '\\') {
        if (pos_ >= text_.size()) {
          throw Error("unfinished escape sequence");
        }
        const char esc = text_[pos_++];
        switch (esc) {
          case '"':
          case '\\':
          case '/': out.push_back(esc); break;
          case 'b': out.push_back('\b'); break;
          case 'f': out.push_back('\f'); break;
          case 'n': out.push_back('\n'); break;
          case 'r': out.push_back('\r'); break;
          case 't': out.push_back('\t'); break;
          case 'u': {
            // Keep parser lightweight: accept and preserve unicode escape
            // marker.
            if (pos_ + 4 > text_.size()) {
              throw Error("incomplete unicode escape");
            }
            out.append("\\u");
            for (int i = 0; i < 4; ++i) {
              const char h = text_[pos_++];
              if (!((h >= '0' && h <= '9') || (h >= 'a' && h <= 'f') ||
                      (h >= 'A' && h <= 'F'))) {
                throw Error("invalid unicode escape");
              }
              out.push_back(h);
            }
            break;
          }
          default: throw Error("invalid escape character");
        }
      } else {
        out.push_back(c);
      }
    }
    throw Error("unterminated string");
  }

  ll ParseNonNegativeInteger() {
    const std::size_t start = pos_;
    if (Match('-')) {
      throw Error("platform count must be non-negative");
    }
    if (Match('0')) {
      if (pos_ < text_.size() &&
          std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        throw Error("leading zeros are not allowed");
      }
      return 0;
    }
    if (pos_ >= text_.size() ||
        !std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
      throw Error("expected integer");
    }
    while (pos_ < text_.size() &&
           std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
      ++pos_;
    }
    const string token = text_.substr(start, pos_ - start);
    try {
      return std::stoll(token);
    } catch (...) {
      throw Error("integer out of range");
    }
  }

  void SkipLiteral(std::string_view lit) {
    if (text_.substr(pos_, lit.size()) != lit) {
      throw Error("invalid literal");
    }
    pos_ += lit.size();
  }

  void SkipNumber() {
    const std::size_t start = pos_;
    if (Match('-') &&
        (pos_ >= text_.size() ||
            !std::isdigit(static_cast<unsigned char>(text_[pos_])))) {
      throw Error("invalid number");
    }

    if (Match('0')) {
      if (pos_ < text_.size() &&
          std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        throw Error("invalid number");
      }
    } else {
      if (pos_ >= text_.size() ||
          !std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        throw Error("invalid number");
      }
      while (pos_ < text_.size() &&
             std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        ++pos_;
      }
    }

    if (Match('.')) {
      if (pos_ >= text_.size() ||
          !std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        throw Error("invalid number");
      }
      while (pos_ < text_.size() &&
             std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        ++pos_;
      }
    }

    if (Match('e') || Match('E')) {
      if (Match('+') || Match('-')) {
      }
      if (pos_ >= text_.size() ||
          !std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        throw Error("invalid exponent");
      }
      while (pos_ < text_.size() &&
             std::isdigit(static_cast<unsigned char>(text_[pos_]))) {
        ++pos_;
      }
    }

    if (start == pos_) {
      throw Error("invalid number");
    }
  }

  void SkipArray() {
    Expect('[');
    SkipWs();
    if (Match(']')) {
      return;
    }
    while (true) {
      SkipValue();
      SkipWs();
      if (Match(',')) {
        SkipWs();
        continue;
      }
      Expect(']');
      return;
    }
  }

  void SkipObject() {
    Expect('{');
    SkipWs();
    if (Match('}')) {
      return;
    }
    while (true) {
      SkipWs();
      ParseString();
      SkipWs();
      Expect(':');
      SkipWs();
      SkipValue();
      SkipWs();
      if (Match(',')) {
        SkipWs();
        continue;
      }
      Expect('}');
      return;
    }
  }

  void SkipValue() {
    SkipWs();
    if (pos_ >= text_.size()) {
      throw Error("unexpected end of input");
    }
    const char c = text_[pos_];
    if (c == '"') {
      ParseString();
      return;
    }
    if (c == '{') {
      SkipObject();
      return;
    }
    if (c == '[') {
      SkipArray();
      return;
    }
    if (c == 't') {
      SkipLiteral("true");
      return;
    }
    if (c == 'f') {
      SkipLiteral("false");
      return;
    }
    if (c == 'n') {
      SkipLiteral("null");
      return;
    }
    SkipNumber();
  }

  std::vector<PlatformCount> ParsePlatformsObject() {
    std::vector<PlatformCount> result;
    Expect('{');
    SkipWs();
    if (Match('}')) {
      return result;
    }
    while (true) {
      SkipWs();
      const string name = ParseString();
      SkipWs();
      Expect(':');
      SkipWs();
      const ll count = ParseNonNegativeInteger();
      result.push_back({name, count});
      SkipWs();
      if (Match(',')) {
        SkipWs();
        continue;
      }
      Expect('}');
      return result;
    }
  }

  string text_;
  std::size_t pos_;
};

string EscapeXml(const string& s) {
  string out;
  out.reserve(s.size() + 16);
  for (char c : s) {
    switch (c) {
      case '&': out += "&amp;"; break;
      case '<': out += "&lt;"; break;
      case '>': out += "&gt;"; break;
      case '"': out += "&quot;"; break;
      case '\'': out += "&apos;"; break;
      default: out.push_back(c); break;
    }
  }
  return out;
}

string ReadAll(const fs::path& path) {
  std::ifstream ifs(path);
  if (!ifs) {
    throw std::runtime_error("cannot open input file: " + path.string());
  }
  std::ostringstream buffer;
  buffer << ifs.rdbuf();
  return buffer.str();
}

void WriteSvg(
    const fs::path& output_path, const std::vector<PlatformCount>& data) {
  const int width = 1600;
  const int height = 860;
  const int margin_left = 95;
  const int margin_right = 40;
  const int margin_top = 78;
  const int margin_bottom = 190;
  const int plot_w = width - margin_left - margin_right;
  const int plot_h = height - margin_top - margin_bottom;
  const int title_y = 44;

  ll max_count = 0;
  for (const auto& item : data) {
    max_count = std::max(max_count, item.count);
  }
  // Round y-axis to "nice" steps (1/2/5 * 10^k) for cleaner visuals.
  const int target_ticks = 6;
  const double suggested_max =
      std::max(1.0, static_cast<double>(max_count) * 1.15);
  const double raw_step = suggested_max / target_ticks;
  const double mag =
      std::pow(10.0, std::floor(std::log10(std::max(raw_step, 1.0))));
  const double normalized = raw_step / mag;
  double step = 1.0;
  if (normalized <= 1.0) {
    step = 1.0;
  } else if (normalized <= 2.0) {
    step = 2.0;
  } else if (normalized <= 5.0) {
    step = 5.0;
  } else {
    step = 10.0;
  }
  step *= mag;
  if (step < 1.0) {
    step = 1.0;
  }

  const ll y_step = static_cast<ll>(std::llround(step));
  ll y_max = static_cast<ll>(std::ceil(static_cast<double>(max_count) * 1.15 /
                                       static_cast<double>(y_step))) *
             y_step;
  if (y_max <= 0) {
    y_max = y_step;
  }
  const int y_ticks = static_cast<int>(y_max / y_step);

  const double n = static_cast<double>(data.size());
  const double slot_w = plot_w / n;
  const double bar_w = slot_w * 0.78;

  std::error_code ec;
  fs::create_directories(output_path.parent_path(), ec);
  if (ec) {
    throw std::runtime_error("cannot create output directory: " +
                             output_path.parent_path().string());
  }

  std::ofstream ofs(output_path);
  if (!ofs) {
    throw std::runtime_error(
        "cannot open output file: " + output_path.string());
  }

  ofs << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
  ofs << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << width
      << "\" height=\"" << height << "\" viewBox=\"0 0 " << width << " "
      << height << "\">\n";
  ofs << "  <rect x=\"0\" y=\"0\" width=\"" << width << "\" height=\"" << height
      << "\" fill=\"#ececec\"/>\n";
  ofs << "  <rect x=\"" << margin_left << "\" y=\"" << margin_top
      << "\" width=\"" << plot_w << "\" height=\"" << plot_h
      << "\" fill=\"#f7f7f7\"/>\n";

  ofs << "  <text x=\"" << (width / 2) << "\" y=\"" << title_y
      << "\" text-anchor=\"middle\" font-size=\"22\" font-family=\"Segoe UI, "
         "Arial, sans-serif\" fill=\"#111\">"
      << "Programming Platform Problem Statistics</text>\n";

  // Horizontal grid and y-axis ticks.
  for (int i = 0; i <= y_ticks; ++i) {
    const double t = static_cast<double>(i) / y_ticks;
    const double y = margin_top + plot_h * (1.0 - t);
    const ll value = static_cast<ll>(std::llround(y_max * t));
    ofs << "  <line x1=\"" << margin_left << "\" y1=\"" << y << "\" x2=\""
        << (margin_left + plot_w) << "\" y2=\"" << y
        << "\" stroke=\"#c0c4c9\" stroke-width=\"1.1\" "
           "stroke-dasharray=\"6,5\"/>\n";
    ofs << "  <text x=\"" << (margin_left - 10) << "\" y=\"" << (y + 5)
        << "\" text-anchor=\"end\" font-size=\"13\" font-family=\"Segoe UI, "
           "Arial, sans-serif\" fill=\"#222\">"
        << value << "</text>\n";
  }

  // Bars.
  for (std::size_t i = 0; i < data.size(); ++i) {
    const auto& item = data[i];
    const double x = margin_left + i * slot_w + (slot_w - bar_w) / 2.0;
    const double bar_h =
        static_cast<double>(item.count) / static_cast<double>(y_max) * plot_h;
    const double y = margin_top + plot_h - bar_h;
    const double cx = x + bar_w / 2.0;
    const double baseline = margin_top + plot_h;

    ofs << "  <rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << bar_w
        << "\" height=\"" << bar_h
        << "\" fill=\"#e6adb8\" stroke=\"#f3d5dc\" stroke-width=\"1\"/>\n";
    ofs << "  <text x=\"" << cx << "\" y=\"" << (y - 8)
        << "\" text-anchor=\"middle\" font-size=\"13\" font-family=\"Segoe UI, "
           "Arial, sans-serif\" fill=\"#121212\">"
        << item.count << "</text>\n";

    const string label = EscapeXml(item.name);
    ofs << "  <g transform=\"translate(" << cx << "," << (baseline + 16)
        << ") rotate(-45)\">\n";
    ofs << "    <text text-anchor=\"end\" font-size=\"13\" font-family=\"Segoe "
           "UI, Arial, sans-serif\" fill=\"#121212\">"
        << label << "</text>\n";
    ofs << "  </g>\n";
  }

  // Draw axis lines after bars so the bottom border is not covered.
  ofs << "  <line x1=\"" << margin_left << "\" y1=\"" << margin_top
      << "\" x2=\"" << margin_left << "\" y2=\"" << (margin_top + plot_h)
      << "\" stroke=\"#1f1f1f\" stroke-width=\"1.4\"/>\n";
  ofs << "  <line x1=\"" << margin_left << "\" y1=\"" << (margin_top + plot_h)
      << "\" x2=\"" << (margin_left + plot_w) << "\" y2=\""
      << (margin_top + plot_h)
      << "\" stroke=\"#1f1f1f\" stroke-width=\"1.4\"/>\n";

  // Axis labels.
  ofs << "  <text x=\"" << (margin_left + plot_w / 2.0) << "\" y=\""
      << (height - 25)
      << "\" text-anchor=\"middle\" font-size=\"14\" font-family=\"Segoe UI, "
         "Arial, sans-serif\" fill=\"#111\">Platforms</text>\n";
  ofs << "  <g transform=\"translate(28," << (margin_top + plot_h / 2.0)
      << ") rotate(-90)\">\n";
  ofs << "    <text text-anchor=\"middle\" font-size=\"14\" "
         "font-family=\"Segoe UI, Arial, sans-serif\" fill=\"#111\">Problems "
         "Count</text>\n";
  ofs << "  </g>\n";

  ofs << "</svg>\n";

  if (!ofs.good()) {
    throw std::runtime_error(
        "failed while writing output file: " + output_path.string());
  }
}

void PrintUsage(const char* prog) {
  std::cerr << "Usage: " << prog << " [--input <path>] [--output <path>]\n";
}

}  // namespace

int main(int argc, char* argv[]) {
  fs::path input_path = "Z_pack/summary.json";
  fs::path output_path = "Z_pack/chart.svg";

  for (int i = 1; i < argc; ++i) {
    const string arg = argv[i];
    if (arg == "--input") {
      if (i + 1 >= argc) {
        PrintUsage(argv[0]);
        return 1;
      }
      input_path = argv[++i];
    } else if (arg == "--output") {
      if (i + 1 >= argc) {
        PrintUsage(argv[0]);
        return 1;
      }
      output_path = argv[++i];
    } else if (arg == "-h" || arg == "--help") {
      PrintUsage(argv[0]);
      return 0;
    } else {
      std::cerr << "Unknown argument: " << arg << "\n";
      PrintUsage(argv[0]);
      return 1;
    }
  }

  try {
    const string json_text = ReadAll(input_path);
    JsonParser parser(json_text);
    const std::vector<PlatformCount> platforms = parser.ParsePlatforms();
    WriteSvg(output_path, platforms);

    std::cout << "Generated chart: " << fs::absolute(output_path) << "\n";
    std::cout << "Platforms: " << platforms.size() << "\n";
    return 0;
  } catch (const std::exception& ex) {
    std::cerr << "[error] " << ex.what() << "\n";
    return 1;
  }
}
