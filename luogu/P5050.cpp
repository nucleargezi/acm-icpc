#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
// #include "YRS/poly/multi.hpp"
#include "YRS/poly/multi_ntt.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, Q);
  VEC(mint, f, N + 1);
  VEC(mint, x, Q);
  for (mint e : X.eval_ntt(f, x)) print(e);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"