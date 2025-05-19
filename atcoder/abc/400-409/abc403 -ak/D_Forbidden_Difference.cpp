#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d);
  VEC(ll, a, n);
  if (d == 0) {
    unique(a);
    iroha UL(n - len(a));
  }
  map<ll, vector<ll>> M;
  FOR(i, n) M[a[i] % d].emplace_back(a[i] / d);
  ll ans = 0;
  for (meion [_, v] : M) {
    sort(v);
    ll sum = 0, dp[2]{}, pre = -1; 
    for (meion [x, y] : run_length(v)) {
      if (pre != x - 1) {
        ans += MAX(dp[0], dp[1]);
        sum = 0;
        dp[0] = dp[1] = 0;
      }
      sum += y;
      std::tie(dp[0], dp[1]) = pair(dp[1] + y, MAX(dp[0], dp[1]));
      pre = x;
    }
    ans += MAX(dp[0], dp[1]);
  }
  UL(n - ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"