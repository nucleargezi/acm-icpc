#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(p);
  vector<ll> dp(p + 1, inf<int>);
  dp[0] = 0;
  FOR(i, 1, p + 1) FOR(k, 2, p + 2) {
    if (k * (k - 1) / 2 > i) break;
    chmin(dp[i], dp[i - k * (k - 1) / 2] + k);
  }
  UL(dp[p], dp[p] * (dp[p] - 1) / 2 - p);
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