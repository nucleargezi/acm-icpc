#include "YRS/all.hpp"

PLL f(ll x) { return {x >> 32, x & uint(-1)}; }
void Yorisou() {
  LL(N, W);
  VEC(ll, a, N);
  vc<ll> dp(1 << N, inf<ll>);
  vc<int> fa(1 << N, -1);
  dp[0] = 0;
  FOR(s, 1 << N) if (dp[s] != inf<ll>) {
    FOR(i, N) if (not(s >> i & 1)) {
      Z [b, hs] = f(dp[s]);
      int t = 1 << i | s;
      if (hs + a[i] > W) {
        if (chmin(dp[t], (b + 1ll) << 32 | a[i])) fa[t] = s;
      } else {
        if (chmin(dp[t], dp[s] + a[i])) fa[t] = s;
      }
    }
  }

  ll x = dp.back();
  x = (x >> 32) + not not(x & uint(-1));
  print(x);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"