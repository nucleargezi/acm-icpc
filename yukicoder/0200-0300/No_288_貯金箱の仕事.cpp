#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"

void Yorisou() {
  LL(N, M);
  VEC(ll, a, N);
  VEC(ll, k, N);
  FOR(i, N) M -= a[i] * k[i];
  if (M > 0) return print(-1);
  M = -M;
  constexpr int sz = 500 * 500 + 1;
  vc<ll> dp(sz, inf<ll>);
  dp[0] = 0;
  for (ll x : a) {
    FOR(i, sz - x) if (dp[i] != inf<ll>) {
      chmin(dp[i + x], dp[i] + 1);
    }
  }
  ll e = a.back(), d = ceil(max<ll>(0, M - sz + 1), e);
  M -= e * d;
  if (dp[M] == inf<ll>) return print(-1);
  print(dp[M] + d);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"