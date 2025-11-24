// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/lis.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, M, l, t);
  vector<ll> a(N + 1);
  a[0] = 0, a[N] = l;
  FOR(i, 1, N) IN(a[i]);
  VEC(ll, v, N);
  static constexpr ll L = 27720;
  FOR(i, N + 1) a[i] *= L;
  VEC(PLL, b, M);
  for (Z &[x, y] : b) x *= L, y *= L;
  ++M;
  b.ep(L * l, t * L);
  vector<ll> lm(N + 1);
  FOR(i, 1, N + 1) lm[i] = lm[i - 1] + (a[i] - a[i - 1]) / v[i - 1];
  if (lm[N] > b[M - 1].se) return print(-1);
  int k = 1;
  vector<ll> f;
  FOR(i, M) {
    ll t = b[i].se;
    while (a[k] < b[i].fi) ++k;
    ll g = t - lm[k - 1] - (b[i].fi - a[k - 1]) / v[k - 1];
    if (g < 0) g = inf<ll> / 2;
    f.ep(g);
  }
  vector<ll> g;
  for (ll x : f) if (x <= f.back()) g.ep(x);
  FOR(i, len(g)) g[i] += i;
  Z x = len(lis(g));
  print(M - x);
}
#include "YRS/Z_H/main.hpp"