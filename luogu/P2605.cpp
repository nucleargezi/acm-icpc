#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/range_min_add.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = range_min_add<ll>;
void Yorisou() {
  INT(N, K);
  vc<int> x(N - 1), c(N), s(N), w(N);
  IN(x, c, s, w);
  x.insert(x.begin(), 0);
  vc<int> L(N), R(N);
  vvc<PII> v(N + 1);
  FOR(i, N) {
    int l = lb(x, x[i] - s[i]), r = ub(x, x[i] + s[i]) - 1;
    int g = min(r + 1, l) + 1;
    if (g > 0) v[r + 1].ep(g, w[i]);
  }
  vc<ll> dp(N + 1, inf<ll> / 2), ndp(dp);
  dp[0] = 0;
  DS seg;
  ll ans = inf<ll>;
  FOR(K + 1) {
    seg.build(dp);
    fill(all(ndp), inf<ll> / 2);
    FOR(x, N) {
      for (Z [g, w] : v[x]) seg.apply(0, g, w);
      ll g = seg.prod(0, x + 1);
      if (g < inf<ll> / 2) ndp[x + 1] = g + c[x];
    }
    for (Z [g, w] : v[N]) seg.apply(0, g, w);
    chmin(ans, seg.prod_all());
    dp.swap(ndp);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"