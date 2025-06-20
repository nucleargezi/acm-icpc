#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s);
  LL(n);
  string ans = s + char('z' + 1);
  FOR(n) {
    S(t);
    if (len(t) >= len(s) and t.substr(0, len(s)) == s) {
      chmin(ans, t);
    }
  }
  if (ans == s + char('z' + 1)) ans = s;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"