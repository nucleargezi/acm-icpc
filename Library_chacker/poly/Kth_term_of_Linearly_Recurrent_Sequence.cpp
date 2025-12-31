#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  LL(K);
  VEC(mint, f, N);
  VEC(mint, g, N);
  FOR(i, N) g[i] = -g[i];
  g.insert(g.begin(), 1);
  f = convolution(f, g);
  f.resize(N);
  print(coef_of_rational_fps(f, g, K));
}
#include "YRS/aa/main.hpp"