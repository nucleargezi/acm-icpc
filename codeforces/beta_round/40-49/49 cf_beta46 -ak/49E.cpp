#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
constexpr int N = 26;
using bs = bitset<N>;
void Yorisou() {
  S(s, t);
  const ll ls = len(s), lt = len(t);
  for (char &c : s) c -= 'a';
  for (char &c : t) c -= 'a';
  bitset<N> vis[N][N]{};
  LL(n);
  FOR(n) {
    S(s);
    for (char &c : s) c -= 'a';
    vis[s[3]][s[4]][s[0]] = 1;
  }
  bs dps[ls][ls]{}, dpt[lt][lt]{};
  FOR(i, ls) dps[i][i][s[i]] = 1;
  FOR(i, lt) dpt[i][i][t[i]] = 1;
  FOR_R(l, ls) FOR(r, l, ls) FOR(m, l, r) {
    FOR(a, N) FOR(b, N) if (dps[l][m][a] and dps[m + 1][r][b]) {
      dps[l][r] |= vis[a][b];
    }
  }
  FOR_R(l, lt) FOR(r, l, lt) FOR(m, l, r) {
    FOR(a, N) FOR(b, N) if (dpt[l][m][a] and dpt[m + 1][r][b]) {
      dpt[l][r] |= vis[a][b];
    }
  }
  uint dp[ls + 1][lt + 1];
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  FOR(i, ls) FOR(k, lt) {
    FOR(j, i + 1) FOR(l, k + 1) {
      if (dp[j][l] != -1 and (dps[j][i] & dpt[l][k]).any()) {
        chmin(dp[i + 1][k + 1], dp[j][l] + 1);
      }
    }
  }
  UL(MAX<int>(-1, dp[ls][lt]));
}
#include "MeIoN_Lib/Z_H/main.hpp"