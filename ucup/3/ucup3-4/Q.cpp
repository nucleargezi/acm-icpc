#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  sort(a);
  vector<ll> dp(N, inf<ll>);
  dp[0] = 0;
  FOR(i, N - 1) if (dp[i] != inf<ll>) {
    ll g = 1;
    FOR(k, 2) {
      int id = lower_bound(a, a[i] * (g + 1));
      chmin(dp[id - 1], dp[i] + a[id - 1] / a[i]);
      if(id == N) break;
      g = a[id] / a[i];
    }
  }
  print(dp.back());
}
#include "YRS/Z_H/main.hpp"