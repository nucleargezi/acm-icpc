#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  SV(s, 'A');
  const int n = len(s);
  int m[]{1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 0};
  ll ans = 0;
  FOR(50) {
    FOR(i, n) s[i] = (s[i] + 1) % 26;
    ll r = 0;
    FOR(i, n) r += m[s[i]];
    chmax(ans, r);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"