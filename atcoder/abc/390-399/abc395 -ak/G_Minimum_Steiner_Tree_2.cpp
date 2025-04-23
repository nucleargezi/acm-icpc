#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  ll v[n][n];
  FOR(i, n) FOR(k, n) {
    IN(v[i][k]);
  }
  FOR(i, n) FOR(x, n) FOR(y, n) {
    chmin(v[x][y], v[x][i] + v[i][y]);
  }
  ll dp[n + 1][n][1 << k];
  std::fill(dp[0][0], dp[0][0] + n * (n + 1) * (1 << k), inf<ll> >> 2);
  FOR(i, n) dp[n][i][0] = dp[i][i][0] = 0;
  FOR(i, k) dp[n][i][1 << i] = dp[i][i][1 << i] = 0;
  FOR(msk, 1 << k) {
    FOR_subset(s, msk) if (s != msk) {
      FOR(i, n + 1) FOR(j, n) {
        chmin(dp[i][j][msk], dp[n][j][s] + dp[i][j][msk - s]);
      }
    }
    FOR(i, n) FOR(j, n) chmin(dp[n][j][msk], dp[n][i][msk] + v[i][j]);
    FOR(i, n) FOR(j, n) chmin(dp[i][j][msk], dp[n][j][msk] + dp[i][j][0]);
    FOR(x, n) FOR(i, n) FOR(j, n) {
      chmin(dp[x][j][msk], dp[x][i][msk] + v[i][j]);
    }
    FOR(i, n + 1) FOR(j, k) {
      if (msk >> j & 1 ^ 1) {
        chmin(dp[i][j][1 << j | msk], dp[i][j][msk]);
      }
    }
  }
  LL(q);
  FOR(q) {
    LL(x, y);
    UL(dp[--x][--y][(1 << k) - 1]);
  }
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