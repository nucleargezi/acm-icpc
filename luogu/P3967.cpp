#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/hungarian.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  retsu<ll> g(N, N);
  IN(g.A);
  Z [s, mat, x, y] = hungarian<ll, false>(g);
  print(s);
  vc<PII> f;
  FOR(i, N) f.ep(i, mat[i]);
  sort(f);
  for (Z [i, k] : f) {
    ll x = g[i][k];
    g[i][k] = -inf<int>;
    Z [ns, m, X, Y] = hungarian<ll, false>(g);
    if (ns != s) print(i + 1, k + 1);
    g[i][k] = x;
  }
}
#include "YRS/Z_H/main.hpp"