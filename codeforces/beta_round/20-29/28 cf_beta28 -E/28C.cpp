#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  INT(n, m);
  VEC(int, a, m);
  vector c(n + 1, vector<RE>(n + 1)), dp(c);
  FOR(i, n + 1) {
    c[i][0] = 1;
    FOR(k, 1, i + 1) {
      c[i][k] = c[i - 1][k] + c[i - 1][k - 1];
    }
  }
  dp[0][0] = 1;
  FOR(i, m) {
    vector ndp(n + 1, vector<RE>(n + 1));
    FOR(k, n + 1) FOR(j, k + 1) FOR(l, n + 1 - k) {
      ndp[k + l][MAX(j, ceil(l, a[i]))] += dp[k][j] * c[k + l][k];
    }
    dp.swap(ndp);
  }
  RE ans{};
  FOR(i, n + 1) ans += dp[n][i] * i;
  UL(ans / std::pow<RE>(m, n));
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