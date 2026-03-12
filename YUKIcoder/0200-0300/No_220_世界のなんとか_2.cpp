#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  vc<array<array<ll, 2>, 3>> dp(N);
  FOR(i, 10) dp[0][i % 3][i == 3] += 1;
  FOR(i, 1, N) FOR(k, 10) FOR(j, 3) FOR(t, 2) {
    int nx = (k + j) % 3;
    dp[i][nx][t or k == 3] += dp[i - 1][j][t];
  }
  ll s = dp[N - 1][0][0] + dp[N - 1][0][1] + dp[N - 1][1][1] + dp[N - 1][2][1];
  print(s - 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"