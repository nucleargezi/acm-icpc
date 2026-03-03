#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/poly/coef_of_rationals.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(K, N);
  VEC(mint, g, N);
  VEC(mint, f, N);
  FOR(i, N) g[i] = -g[i];
  g.insert(begin(g), 1);
  f = X.conv(f, g);
  sh(f, N);
  print(X.coef_of_rationals(f, g, K));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"