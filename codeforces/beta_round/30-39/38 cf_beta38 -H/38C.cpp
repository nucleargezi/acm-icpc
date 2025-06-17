#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, l);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, l, 101) {
    ll s = 0;
    FOR(k, n) s += a[k] / i;
    chmax(ans, s * i);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"