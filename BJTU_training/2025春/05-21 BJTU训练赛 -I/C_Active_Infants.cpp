#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector dp(n + 1, vector(n + 1, -inf<ll>));
  dp[0][0] = 0;
  meion I = argsort(a);
  reverse(I);
  FOR(i, n) {
    FOR(x, i + 1) {
      ll y = i - x;
      chmax(dp[i + 1][x + 1], dp[i][x] + (I[i] - x) * a[I[i]]);
      chmax(dp[i + 1][x], dp[i][x] + (n - y - 1 - I[i]) * a[I[i]]);
    }
  }
  ll ans = 0;
  FOR(i, n + 1) chmax(ans, dp[n][i]);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp" 