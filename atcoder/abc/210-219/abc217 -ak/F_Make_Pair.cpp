#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  VEC(PLL, fr, m);
  bool f[n << 1][n << 1]{};
  for (meion &[x, y] : fr) {
    --x, --y;
    f[x][y] = f[y][x] = 1;
  }
  mint dp[n << 1][n << 1];
  FOR(i, (n << 1) - 1) {
    dp[i + 1][i] = 1;
  }
  FOR_R(l, n << 1) FOR(r, l, n << 1) {
    if (r - l + 1 & 1) continue;
    if (f[l][r]) dp[l][r] += dp[l + 1][r - 1];
    FOR(m, l + 1, r) {
      if (f[m][r])
        dp[l][r] += dp[l][m - 1] * dp[m + 1][r - 1] * C<mint>(r - l + 1 >> 1, m - l + 1 >> 1);
    }
  }
  UL(dp[0][(n << 1) - 1]);
}
#include "MeIoN_Lib/Z_H/main.hpp"