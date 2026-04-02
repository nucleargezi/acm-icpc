#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(a, b, c);
  constexpr int N = 101;
  static RE dp[N][N][N];
  FOR(i, N) FOR(k, N) FOR(j, N) {
    if (not k and not j) {
      dp[i][k][j] = 1;
      continue;
    }
    if (not i) continue;
    if (i and k)
      dp[i][k][j] += RE(i * k) / (i * k + i * j + k * j) * dp[i][k - 1][j];
    if (k and j)
      dp[i][k][j] += RE(k * j) / (i * k + i * j + k * j) * dp[i][k][j - 1];
    if (i and j)
      dp[i][k][j] += RE(j * i) / (i * k + i * j + k * j) * dp[i - 1][k][j];
  }
  UL(dp[a][b][c], dp[b][c][a], dp[c][a][b]);
}
#include "MeIoN_Lib/Z_H/main.hpp"