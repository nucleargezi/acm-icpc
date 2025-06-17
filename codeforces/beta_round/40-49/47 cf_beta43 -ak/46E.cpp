#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VVEC(ll, a, n, m);
  FOR(i, n) a[i] = pre_sum<false>(a[i]);
  vector<ll> dp = a[0];
  FOR(i, 1, n) {
    vector<ll> ndp(m, -inf<ll>);
    if (i & 1) {
      FOR_R(i, m - 1) chmax(dp[i], dp[i + 1]);
      FOR(k, m - 1) ndp[k] = a[i][k] + dp[k + 1];
    } else {
      FOR(i, m - 1) chmax(dp[i + 1], dp[i]);
      FOR(k, 1, m) ndp[k] = a[i][k] + dp[k - 1];
    }
    dp.swap(ndp);
  }
  UL(QMAX(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"