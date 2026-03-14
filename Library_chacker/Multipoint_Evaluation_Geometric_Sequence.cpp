#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/poly/multi_geo.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, m, a, r);
  VEC(mint, f, N);
  print(X.eval_geo(f, a, r, m));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"