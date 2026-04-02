#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  for (meion &[x, y] : a) {
    std::tie(x, y) = PLL(x - y, x + y);
  }
  sort(a);
  vector<ll> dp(n + 1, inf<ll>);
  FOR(i, n) {
    chmin(dp[upper_bound(dp, a[i].first)], a[i].second);
  }
  UL(lower_bound(dp, inf<ll>));
}
#include "MeIoN_Lib/Z_H/main.hpp"