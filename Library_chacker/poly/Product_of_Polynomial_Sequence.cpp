#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/poly/conv_all.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  vc<fps> a(N);
  FOR(i, N) {
    INT(N);
    ++N;
    VEC(mint, f, N);
    a[i] = std::move(f);
  }
  print(X.conv_all(a));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"