#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  a += a[0];
  ll mx = inf<ll>;
  PLL ans;
  FOR(i, n) {
    if (chmin(mx, ABS(a[i + 1] - a[i]))) {
      ans = {i + 1, (i + 1) % n + 1};
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"