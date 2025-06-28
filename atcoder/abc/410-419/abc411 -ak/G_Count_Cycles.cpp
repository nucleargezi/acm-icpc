#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  ll v[n][n]{};
  FOR(m) {
    LL(x, y);
    --x, --y;
    ++v[x][y], ++v[y][x];
  }
  const int N = 1 << n;
  vector dp(N, array<mint, 20>{});
  mint ans = -m;
  FOR(i, n) dp[1 << i][i] = 1;
  FOR(msk, N) FOR(i, n) if (dp[msk][i].val) {
    FOR(k, n) if (v[i][k] and lowbit(msk) <= k) {
      if (msk >> k & 1) {
        if (lowbit(msk) == k) {
          ans += dp[msk][i] * v[i][k];
        }
      } else {
        dp[1 << k | msk][k] += dp[msk][i] * v[i][k];
      }
    }
  }
  UL(ans / 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"