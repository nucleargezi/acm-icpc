#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, t);
  int dp[20][11][4][4]{};
  FOR(i, 4) FOR(k, i + 1, 4) dp[0][0][i][k] = 1;
  FOR(i, 1, n - 1) FOR(k, t + 1) {
    FOR(j, 4) FOR(l, 4) FOR(m, 4) if (l != m) {
      dp[i][k + (l > MAX(j, m))][l][m] += dp[i - 1][k][j][l];
    }
  }
  ll ans{};
  FOR(i, 4) FOR(k, i) ans += dp[n - 2][t][i][k];
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}