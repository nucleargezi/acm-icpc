#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
void Yorisou() {
  INT(n, k);
  VEC(mint, a, n);
  mint dp[n + 1][k + 1];
  mint ans;
  FOR(i, n) {
    dp[i][0] += 1;
    FOR(j, k + 1) FOR(l, k - j + 1) {
      dp[i + 1][j + l] += dp[i][j] * C_dense<mint>(k - j, l) * a[i].ksm(l);
    }
    ans += dp[i + 1][k];
  }
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