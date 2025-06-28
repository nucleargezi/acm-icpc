#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, h, m);
  VEC(PLL, a, n);
  vector<ll> dp(m + 1, inf<int>), ndp(m + 1);
  dp[0] = 0;
  FOR(i, n) {
    fill(ndp, inf<int>);
    FOR(x, m + 1) if (dp[x] != inf<ll>) {
      if (x + a[i].second <= m) {
        chmin(ndp[x + a[i].second], dp[x]);
      }
      chmin(ndp[x], dp[x] + a[i].first);
    }
    dp.swap(ndp);
    bool f = 0;
    FOR(x, m + 1) if (dp[x] <= h) {
      f = 1;
      break;
    }
    if (not f) iroha UL(i);
  }
  UL(n);
}
#include "MeIoN_Lib/Z_H/main.hpp"