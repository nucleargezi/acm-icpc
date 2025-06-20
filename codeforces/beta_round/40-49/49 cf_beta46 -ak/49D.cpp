#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  ll ans = n;
  FOR(2) {
    FOR(i, n) s[i] ^= 1;
    ll r = 0;
    FOR(i, 0, n, 2) r += s[i] ^ 1;
    FOR(i, 1, n, 2) r += s[i];
    chmin(ans, r);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"