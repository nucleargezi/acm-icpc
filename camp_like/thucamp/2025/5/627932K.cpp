#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  S(s);
  string ans;
  meion f = [&](string s) -> void {
    if (std::isdigit(s[0])) {
      string ret;
      for (int t = 0; char c : std::views::reverse(s)) {
        ret += c;
        if (++t % 3 == 0) ret += '\'';
      }
      if (ret.back() == '\'') ret.pop_back();
      ans += reversed(ret);
    } else {
      ans += s;
    }
  };
  int pr = 0;
  const int n = len(s);
  FOR(i, n) {
    if (s[i] == '=') {
      f(s.substr(pr, i - pr));
      pr = i + 1;
      ans += '=';
    } else if (s[i] == '+') {
      f(s.substr(pr, i - pr));
      pr = i + 1;
      ans += '+';
    }
  }
  f(s.substr(pr));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"