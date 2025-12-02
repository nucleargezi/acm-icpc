#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/slope/CHT.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(ll, a, N);
  vc<ll> c = pre_sum(a);
  ll s = c[N];
  vc<ll> dp(N + 1), ndp(dp);
  FOR(i, 1, N + 1) dp[i] = c[i] * c[i];
  FOR(k, 1, M) {
    fill(all(ndp), inf<ll>);
    CHT_min<ll> g;
    g.add(c[k] * -2, dp[k] + c[k] * c[k]);
    FOR(i, k + 1, N + 1) {
      ll x = c[i], t = g.min(c[i]);
      ndp[i] = x * x + t;
      g.add(x * -2, dp[i] + x * x);
    }
    dp.swap(ndp);
  }
  print(dp[N] * M - s * s);
}
#include "YRS/Z_H/main.hpp"