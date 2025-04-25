#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(n, x);
  VEC(ll, a, n);
  vector dp(n, vector<ll>(n + 1, -10));
  dp[n - 1][0] = x;
  FOR_R(i, n) {
    if (i + 1 != n) {
      FOR(k, n - i + 1) {
        dp[i][k] = dp[i + 1][k];
      }
    }
    FOR_R(k, 1, n - i + 1) {
      if (dp[i][k - 1] > 0) {
        chmax(dp[i][k], dp[i][k - 1] - (n - i) * a[i]);
      }
    }
  }
  ll ans = 0;
  FOR(i, n) FOR(k, 1, n + 1) {
    if (dp[i][k] > -1) chmax(ans, k);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"