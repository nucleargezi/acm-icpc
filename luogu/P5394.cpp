#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/poly/ffp.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  print(X.ffp_conv(a, b));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"