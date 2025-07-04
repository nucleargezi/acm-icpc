#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  char c;
  int ans = 0;
  static string s[114514];
  int t = 0;
  while (std::cin >> c) {
    if (c == '.') {
      FOR(i, t) ans += s[i] == s[t];
      s[t--] = "";
    } else if (c == ':' or c == ',') {
      ++t;
    } else {
      s[t] += c;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"