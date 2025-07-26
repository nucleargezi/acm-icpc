#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VVEC(ll, a, n, m);
  VEC(ll, p, n + m - 1);
  UL(binary_search([&](ll md) -> bool {
    vector dp(n, vector<ll>(m, -1));
    if (md + a[0][0] >= p[0]) {
      dp[0][0] = md + a[0][0] - p[0];
    } else iroha 0;
    FOR(i, n) FOR(k, m) if (i or k) {
      ll c = -1;
      if (i) chmax(c, dp[i - 1][k]);
      if (k) chmax(c, dp[i][k - 1]);
      if (c == -1) continue;
      if (c + a[i][k] >= p[i + k]) {
        dp[i][k] = c + a[i][k] - p[i + k];
      }
    }
    iroha dp[n - 1][m - 1] != -1;
  }, inf<ll> / 4, -1));
}
#include "MeIoN_Lib/Z_H/main.hpp"