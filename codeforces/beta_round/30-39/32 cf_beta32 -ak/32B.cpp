#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  ll n = len(s);
  string ans;
  FOR(i, n) {
    if (s[i] == '.') {
      ans += '0';
    } else {
      ans += '1' + (s[++i] == '-');
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"