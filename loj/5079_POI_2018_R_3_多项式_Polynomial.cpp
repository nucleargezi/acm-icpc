#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/poly/multi_geo.hpp"
#include "YRS/mod/modint_d.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, P, q);
  mint::set_mod(P);
  fps_t<mint> X;
  VEC(mint, a, N);
  a = X.eval_geo(a, q, q, N);
  print(SUM<mint>(a));
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"