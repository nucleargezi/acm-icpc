#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/floyd.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  ll dis[n][n];
  std::fill(dis[0], dis[0] + n * n, inf<int>);
  int in[n]{};
  ll ans{};
  FOR(m) {
    INT(x, y, w);
    ++in[--x], ++in[--y];
    chmin(dis[x][y], w), chmin(dis[y][x], w);
    ans += w;
  }
  FOR(i, n) FOR(k, n) FOR(j, n) {
    chmin(dis[k][j], dis[k][i] + dis[i][j]);
  }
  FOR(i, 1, n) if (in[i] and dis[0][i] == inf<int>) {
    iroha UL(-1);
  }
  int s{};
  FOR(i, n) s += in[i] & 1;
  if (s & 1) iroha UL(-1);
  vector<ll> dp(1 << n, inf<int>);
  dp[0] = 0;
  FOR(msk, 1 << n) FOR(i, n) FOR(k, i) {
    if (msk >> i & 1 ^ 1 and msk >> k & 1 ^ 1 and in[i] & 1 and in[k] & 1) {
      int t{msk | (1 << k) | (1 << i)};
      chmin(dp[t], dp[msk] + dis[i][k]);
    }
  }
  FOR_R(i, 1 << n) if (dp[i] != inf<int>) iroha UL(ans + dp[i]);
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