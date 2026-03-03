#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/poly/fps.hpp"
#include "YRS/poly/online_exp.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  VEC(mint, a, N);
  Z exp = X.online_exp();
  FOR(i, N) a[i] = exp(a[i]);
  print(a);
  // print(X.exp(a));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"