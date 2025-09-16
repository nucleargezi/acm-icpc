#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m, K);
  bool v[n][n]{};
  FOR(m) {
    LL(x, y);
    --x, --y;
    v[x][y] = v[y][x] = 1;
  }
  ll dp[1 << n][1 << n]{};
  FOR(i, n) FOR(k, n) if (v[i][k]) {
    dp[1 << i | 1 << k][1 << i | 1 << k] = 1;
  }
  FOR(msk, 1, 1 << n) if (popcount(msk) > 1) {
    FOR_subset(sub, msk) if (dp[msk][sub]) {
      FOR(i, n) if (msk >> i & 1) {
        FOR(k, n) if (not(msk >> k & 1) and v[i][k]) {
          int t = (sub & (msk ^ (1 << i))) ^ (1 << k);
          if (not((t >> k) ^ 1)) {
            dp[msk | (1 << k)][t] += dp[msk][sub];
          }
        }
      }
    }
  }
  ll ans = 0;
  FOR(i, 1 << n) if (popcount(i) == K) ans += dp[(1 << n) - 1][i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"