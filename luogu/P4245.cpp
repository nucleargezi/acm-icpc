#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/poly/c/bs.hpp"
#include "YRS/mod/modint_d.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, M, P);
  mint::set_mod(P);
  fps_t<mint> X;
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  print(X.conv(a, b));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"