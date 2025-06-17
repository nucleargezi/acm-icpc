#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll s = SUM(a);
  sort(a);
  ll ans = 0;
  FOR(i, n) {
    vector<ll> dp(s + 1);
    dp[a[i]] = 1;
    FOR(k, i + 1, n) {
      FOR_R(j, a[i], s + 1) {
        if (dp[j]) dp[j + a[k]] += dp[j];
      }
    }
    FOR(k, (s >> 1) + 1, MIN(s + 1, (s >> 1) + a[i] + 1)) {
      ans += dp[k];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"