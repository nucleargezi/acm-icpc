#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(PLL, a, n);
  ll t{};
  for (meion [x, y] : a) {
    chmax(t, x + 1);
  }
  vector<ll> dp(t + n + 1, inf<ll> >> 1);
  dp[0] = 0;
  for (meion [x, y] : a) {
    FOR_R(i, x + 1, t + n + 1) {
      chmin(dp[i], dp[i - x - 1] + y);
    }
  }
  ll ans{inf<ll>};
  FOR(i, n, t + n + 1) chmin(ans, dp[i]);
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