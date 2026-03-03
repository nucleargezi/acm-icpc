#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/poly/poly_divmod.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N + 1);
  VEC(mint, g, M + 1);
  Z [d, r] = X.divmod(f, g);
  print(d);
  print(r);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"