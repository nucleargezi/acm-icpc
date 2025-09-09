#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/IO/fmt.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  int n, m;
  static constexpr int N = 2025;
  static mint dp[N][N];
  FOR(i, N) dp[0][i] = 1;
  FOR(i, 1, N) {
    dp[i][0] = dp[i - 1][0];
    FOR(k, 1, N) {
      dp[i][k] = dp[i][k - 1] + dp[i - 1][k];
    }
  }
  FOR(i, N) FOR(k, N) {
    dp[i][k] -= 1;
    dp[i][k] *= dp[i][k];
  }
  while (IN(n, m)) {
    print("{}", dp[n][m].val);
  }
}
#include "YRS/Z_H/main.hpp"