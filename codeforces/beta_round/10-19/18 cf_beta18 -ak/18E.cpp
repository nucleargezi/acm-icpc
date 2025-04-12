#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  char v[n][m];
  FOR(i, n) FOR(k, m) IN(v[i][k]), v[i][k] -= 'a';
  int F[n][26][26]{};
  FOR(i, n) FOR(k, 26) FOR(j, 26) if (k != j) {
    FOR(x, 0, m, 2) F[i][k][j] += k != v[i][x];
    FOR(x, 1, m, 2) F[i][k][j] += j != v[i][x];
  }
  int dp[n][26][26];
  pair<int, int> fa[n][26][26]{};
  std::fill(dp[0][0], dp[0][0] + n * 26 * 26, inf<int>);
  FOR(i, 26) FOR(k, 26) dp[0][i][k] = F[0][i][k];
  FOR(i, 1, n) FOR(k, 26) FOR(j, 26) if (k != j) {
    FOR(l, 26) FOR(r, 26) if (l != r and l != k and r != j) {
      if (chmin(dp[i][l][r], dp[i - 1][k][j] + F[i][l][r])) {
        fa[i][l][r] = {k, j};
      }
    }
  }
  int mx{inf<int>}, x, y;
  FOR(i, 26) FOR(k, 26) {
    if (i != k and chmin(mx, dp[n - 1][i][k])) {
      std::tie(x, y) = pair{i, k};
    }
  }
  char ans[n][m];
  FOR_R(i, n) {
    FOR(k, m) {
      ans[i][k] = ((k & 1) ? y : x) + 'a';
    }
    std::tie(x, y) = fa[i][x][y];
  }
  UL(mx);
  FOR(i, n) UL(string{ans[i], ans[i] + m});
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