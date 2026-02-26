#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/sps/inv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, a, 1 << N);
  vc<mint> c(1 << N);
  c[0] = 1;
  print(sps_inv(a));
}
#include "YRS/aa/main.hpp"