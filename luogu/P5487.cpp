#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/poly/line_inte.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, K);
  VEC(mint, f, N);
  print(X.line_inte(f, K));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"