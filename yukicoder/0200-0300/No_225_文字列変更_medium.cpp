#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M);
  STR(a, b);
  retsu<int> dp(N + 1, M + 1, inf<int>);
  FOR(i, N + 1) dp[i][0] = i;
  FOR(i, M + 1) dp[0][i] = i;
  FOR(i, 1, N + 1) FOR(k, 1, M + 1) {
    chmin(dp[i][k], dp[i - 1][k] + 1);
    chmin(dp[i][k], dp[i][k - 1] + 1);
    chmin(dp[i][k], dp[i - 1][k - 1] + 1 - (a[i - 1] == b[k - 1]));
  }
  print(dp[N][M]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"