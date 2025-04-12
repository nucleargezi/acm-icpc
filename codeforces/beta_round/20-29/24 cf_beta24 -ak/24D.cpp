#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  INT(n, m, x, y);
  RE dp[n][m]{};
  FOR_R(i, n - 1) FOR(100) FOR(k, m) {
    int s{2};
    dp[i][k] += dp[i + 1][k];
    if (k) {
      ++s;
      dp[i][k] += dp[i][k - 1];
    }
    if (k + 1 < m) {
      ++s;
      dp[i][k] += dp[i][k + 1];
    }
    dp[i][k] /= s;
    dp[i][k] += 1;
  }
  UL(dp[--x][--y]);
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