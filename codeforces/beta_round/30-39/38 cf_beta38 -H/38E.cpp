#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  sort(a);
  vector<ll> dp(n);
  dp[0] = a[0].second;
  FOR(i, 1, n) {
    vector<ll> ndp(n);
    FOR(k, i) {
      ndp[k] = dp[k] + a[i].first - a[k].first;
    }
    ndp[i] = inf<ll>;
    FOR(k, i) chmin(ndp[i], dp[k]);
    ndp[i] += a[i].second;
    dp.swap(ndp);
  }
  UL(QMIN(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"