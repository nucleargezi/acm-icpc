#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, n) ans += popcount(a[i]);
  FOR(i, 62) FOR(k, n) {
    if (a[k] >> i & 1) continue;
    if (K >= (1ll << i)) {
      K -= 1ll << i;
      ++ans;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"