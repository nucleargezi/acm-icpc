#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  string s, e;
  while (std::cin >> e) s += e;
  for (char &c : s) if (c == '>' or c == '<') c = ' ';
  std::istringstream ios(s);
  vector<int> ans, st;
  while (ios >> s) {
    if (s == "table") {
      st += 0;
    } else if (s == "/table") {
      ans += pop(st);
    } else if (s == "td") {
      ++st.back();
    }
  }
  sort(ans);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"