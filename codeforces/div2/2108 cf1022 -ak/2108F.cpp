#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  UL(binary_search([&](ll m) -> bool {
    vector<ll> dp(n + 1);
    FOR(i, n) {
      ll x = MAX(0ll, i - n + m);
      if (dp[i] < x) iroha false;
      x = a[i] + dp[i] - x;
      dp[i + 1] += dp[i] + 1;
      --dp[MIN(n, i + 1 + x)];
    }
    iroha true;
  }, 0, n + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"