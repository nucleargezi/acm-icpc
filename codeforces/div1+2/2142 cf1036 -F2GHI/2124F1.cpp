#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  bool vis[n][n]{};
  FOR(i, m) {
    LL(x, y);
    --x, --y;
    vis[x][y] = 1;
  }
  int go[n + 1][n + 1]{};
  FOR_R(i, n) FOR_R(k, n) {
    if (not vis[i][k]) go[i][k] = go[i + 1][k + 1] + 1;
  }
  mint dp[n + 1][n + 1]{};
  dp[n][0] = 1;
  FOR_R(i, 1, n + 1) FOR(k, n) if (dp[i][k].val) {
    FOR(j, i) FOR(l, i - j) if (l or k != i - j) {
      if ((not l and go[j][0] >= i - l) or
          (go[j][l] >= i - j - l and go[i - l][0] >= l)) {
        dp[j][l] += dp[i][k];
      }
    }
  }
  print("{}", std::accumulate(dp[0], dp[0] + n + 1, mint()));
}
#include "MeIoN_Lib/Z_H/main.hpp"