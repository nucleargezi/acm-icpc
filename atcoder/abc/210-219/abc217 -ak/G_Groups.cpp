#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  mint dp[n + 1][n + 1];
  dp[0][0] = 1;
  FOR(i, 1, n + 1) FOR(k, 1, n + 1) {
    dp[i][k] += dp[i - 1][k - 1] + dp[i - 1][k] * (k - (i - 1) / m);
  }
  FOR(i, n) UL(dp[n][i + 1]);
}
#include "MeIoN_Lib/Z_H/main.hpp"