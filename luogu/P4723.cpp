#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(k, N);
  VEC(mint, c, N);
  VEC(mint, a, N);
  FOR(i, N) c[i] = -c[i];
  c.insert(c.begin(), 1);
  a = convolution(a, c);
  a.resize(N);
  print(coef_of_rational_fps(a, c, k));
}
#include "YRS/aa/main.hpp"