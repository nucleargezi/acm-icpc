#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n, K);
  SV(s, '0');
  mint dp[n][K + 1];
  dp[n - 1][0] = 1;
  dp[n - 1][1] = not s[n - 1];
  FOR_R(i, n - 1) {
    FOR(k, K + 1) FOR(j, K - k + 1) {
      dp[i][k + j] += dp[i + 1][k] * C<mint, 0, 1>((k + j + not s[i]) / 2, j);
    }
  }
  print("{}", dp[0][K]);
}
#include "MeIoN_Lib/Z_H/main.hpp"