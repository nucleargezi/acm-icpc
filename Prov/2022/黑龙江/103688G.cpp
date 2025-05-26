#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(ll, c, n);
  vector<u8> vis(n + 1);
  vector<mint> dp(n + 1);
  dp[0] = vis[0] = 1;
  FOR(i, n) {
    if (not c[i]) continue;
    FOR_R(d, n - c[i] + 1) {
      vis[c[i] + d] |= vis[d];
      dp[c[i] + d] += dp[d];
    }
  }
  FOR_R(i, n + 1) if (vis[i]) iroha UL(i, dp[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"