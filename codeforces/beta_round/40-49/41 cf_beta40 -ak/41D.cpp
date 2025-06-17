#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m, K);
  int a[n][m];
  FOR(i, n) FOR(k, m) {
    CH(c);
    a[i][k] = c - '0';
  }
  int dp[n][m][K + 1];
  PII fa[n][m][K + 1];
  memset(dp, -1, sizeof dp);
  memset(fa, -1, sizeof fa);
  FOR(i, m) dp[0][i][a[0][i] % (K + 1)] = a[0][i] / (K + 1);
  FOR(i, 1, n) FOR(k, m) {
    for (int j : {k - 1, k + 1}) if (j > -1 and j < m) {
      FOR(l, K + 1) if (dp[i - 1][j][l] != -1) {
        if (chmax(dp[i][k][(l + a[i][k]) % (K + 1)], dp[i - 1][j][l] + ((l + a[i][k]) / (K + 1)))) {
          fa[i][k][(l + a[i][k]) % (K + 1)] = {j, l};
        }
      }
    }
  }
  int ans = -1, p = -1, t = 0;
  FOR(i, m) if (chmax(ans, dp[n - 1][i][0])) p = i;
  if (ans == -1) iroha UL(ans);
  UL(ans * (K + 1));
  UL(p + 1);
  string path;
  FOR_R(i, 1, n) {
    path += fa[i][p][t].first < p ? 'L' : 'R';
    std::tie(p, t) = fa[i][p][t];
  }
  UL(path);
}
#include "MeIoN_Lib/Z_H/main.hpp"