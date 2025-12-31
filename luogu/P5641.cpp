#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  VEC(mint, a, N);
  vc<mint> f(N), g(N);
  g[0] = 1;
  FOR(i, 1, N) g[i] = g[i - 1] * (K - 1 + i) * inv<mint>(i);
  FOR(i, N) f[i] = g[i] * a[i];
  f = convolution(f, g);
  f.resize(N);
  print(f);
}
#include "YRS/aa/main.hpp"