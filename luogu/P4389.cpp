#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/prod_of_one_minus_xn.hpp"
#include "YRS/po/fps_inv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  Z f = prod_of_inv_one_minus_xn<mint>(a, M);
  FOR(i, 1, M + 1) print(f[i]);
}
#include "YRS/aa/main.hpp"