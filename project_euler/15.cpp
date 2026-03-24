#include "YRS/all.hpp"

void Yorisou() {
  constexpr int n = 21;
  ll dp[n][n]{};
  dp[0][0] = 1;
  FOR(i, n) FOR(k, n) {
    if (i) dp[i][k] += dp[i - 1][k];
    if (k) dp[i][k] += dp[i][k - 1];
  }
  print(dp[n - 1][n - 1]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"