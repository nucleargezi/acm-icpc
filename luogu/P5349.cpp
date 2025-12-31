#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, r);
  set_comb(N + 1);
  VEC(mint, a, N + 1);
  vc<mint> f(N + 1);
  f[0] = 1 - r;
  FOR(i, 1, N + 1) f[i] = -ifac(i) * r;
  f = fps_inv(f);
  mint s = 0;
  FOR(i, N + 1) s += a[i] * fac(i) * f[i];
  print(s);
}
#include "YRS/aa/main.hpp"