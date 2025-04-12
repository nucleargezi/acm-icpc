#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  INT(m);
  VEC(int, b, m);

  int x{-1}, y{-1};
  int dp[n][m]{};
  pair<int, int> f[n][m]{};
  std::fill(f[0], f[0] + n * m, pair{-1, -1});
  FOR(i, n) FOR(k, m) {
    if (a[i] == b[k]) {
      dp[i][k] = 1;
      FOR(j, i) {
        if (a[j] < a[i] and chmax(dp[i][k], dp[j][k] + 1)) {
          f[i][k] = {j, k};
        }
      }
    } else {
      dp[i][k] = k ? dp[i][k - 1] : 0;
      f[i][k] = {i, k - 1};
    }
    if (MIN(x, y) == -1 or dp[i][k] > dp[x][y]) x = i, y = k;
  }
  int L{dp[x][y]};
  UL(L);
  vector<int> path;
  while (~x and ~y) {
    if (a[x] == b[y]) path += a[x];
    std::tie(x, y) = f[x][y];
  }
  reverse(path);
  UL(path);
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