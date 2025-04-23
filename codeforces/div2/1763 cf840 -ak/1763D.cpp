#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = M17;
void Yorisou() {
  LL(n, a, b, x, y);
  --a, --b;
  mint dp[n][n];
  FOR(i, 1, n - 1) {
    if (i == a and x != n) continue;
    if (i == b and y != n) continue;
    dp[i][i] = 1;
  }
  FOR_R(l, n) FOR(r, l + 1, n) {
    ll ln = r - l + 1, t = n - ln + 1;
    if ((a != l or t == x) and (b != l or t == y)) 
      dp[l][r] += dp[l + 1][r];
    if ((a != r or t == x) and (b != r or t == y)) 
      dp[l][r] += dp[l][r - 1];
  }
  UL(dp[0][--n]);
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