#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(a, c, b, d);
  --a, --c, --b, --d;
  ll dp[7][7];
  FOR(i, 49) dp[0][i] = inf<int>;
  FOR(i, 7) dp[i][i] = 0;
  dp[0][1] = dp[1][0] = 
  dp[0][2] = dp[2][0] = 
  dp[2][3] = dp[3][2] = 
  dp[1][3] = dp[3][1] = 
  dp[3][4] = dp[4][3] = 
  dp[3][5] = dp[5][3] = 
  dp[4][6] = dp[6][4] = 
  dp[5][6] = dp[6][5] = 1;
  FOR(x, 7) FOR(i, 7) FOR(k, 7) {
    chmin(dp[i][k], dp[i][x] + dp[x][k]); 
  }
  UL(MIN(dp[a][b] + dp[c][d], dp[a][d] + dp[c][b]));
}
#include "MeIoN_Lib/Z_H/main.hpp"