#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/Z_H/FH.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m, t);
  SV(s, 'a');
  ll c[m][m];
  FOR(i, m) FOR(k, m) IN(c[i][k]);
  static ull dp[1 << 20][20];
  memset(dp, -1, sizeof dp);
  const ull inf = dp[0][0];
  FOR(i, n) dp[1 << i][i] = c[0][s[i]];
  FOR(msk, 1, 1 << n) {
    FOR(i, n) if ((msk >> i & 1)) {
      FOR(k, n) if (not(msk >> k & 1)) {
        int d = popcount(msk & ((1 << i + 1) - 1)),
            dd = popcount(msk & ((1 << k + 1) - 1));
        chmin(dp[msk | (1 << k)][k],
            dp[msk][i] + c[s[i]][s[k]] + t * ABS(d - dd));
      }
    }
  }
  ull ans = inf;
  FOR(i, n) chmin(ans, dp[(1 << n) - 1][i]);
  UL(ans + n * t);
}
#include "MeIoN_Lib/Z_H/main.hpp"