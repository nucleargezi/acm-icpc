#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, V);
  VEC(ll, a, N);
  vc<ll> c = pre_sum(a);
  if (N >= V) return print(c[N]);
  ll ans = inf<ll>, al = c[N];
  V -= N;
  int sz = 2 * N * N;
  c.resize(sz, inf<ll>);
  FOR(i, 1, N + 1) FOR(k, i, sz) chmin(c[k], c[k - i] + c[i]);
  FOR(i, 1, sz) chmin(ans, V / i * c[i] + c[V % i]);
  print(ans + al);
}
#include "YRS/aa/main.hpp"