#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  SV(t, '0');
  ll ans = 0;
  FOR(i, n) {
    ans += MIN(ABS(s[i] - t[i]), 10 - ABS(s[i] - t[i]));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"