#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/poly_inv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N);
  VEC(mint, g, M);
  Z [ok, h] = poly_inv(f, g);
  if (ok) print(len(h)), print(h);
  else print(-1);
}
#include "YRS/aa/main.hpp"