#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"
#include "YRS/po/multipoint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M, K);
  VEC(mint, a, K);
  VEC(mint, f, K);
  VEC(mint, p, M + 1);

  FOR(i, K) f[i] = -f[i];
  f.insert(f.begin(), 1);

  a = convolution(a, f);
  a.resize(K);

  vc<mint> x(K);
  iota(all(x), 0);
  x = multi_eval(p, x);
  FOR(i, K) a[i] -= x[i];
  
  vc<mint> e(M + 2);
  FOR(i, M + 2) e[i] = CC(M + 1, i);
  FOR(i, M + 2) if (i & 1) e[i] = -e[i];

  x.resize(M + 1);
  iota(all(x), 0);
  x = multi_eval(p, x);

  x = convolution(x, e);
  x.resize(M + 1);

  a = convolution(a, e);
  if (len(a) < M + 1) a.resize(M + 1);
  FOR(i, M + 1) a[i] += x[i];
  
  f = convolution(f, e);
  print(coef_of_rational_fps(a, f, N));
}
#include "YRS/aa/main.hpp"