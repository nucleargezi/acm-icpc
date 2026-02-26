#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/line_inte.hpp"
#include "YRS/line/mat.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
using M = mat<mint>;
void Yorisou() {
  LL(N);
  M f(4, 0, 0);
  f[0][0] += 1;
  f[1][0] += 1;
  f[2][0] += 1;
  f[1][1] += 1;
  f[0][1] += 1;
  f[3][1] += 1;
  f[2][2] += 1;
  f[3][2] += 1;
  f[0][2] += 1;
  f[3][3] += 1;
  f[2][3] += 1;
  f[1][3] += 1;
  f = f.pow(N);
  print(f[2][0]);
}
#include "YRS/aa/main.hpp"