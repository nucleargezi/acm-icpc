#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/stiling_1.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  static Z st = stiling_1_mat<mint>(50010, 210);
  INT(n, a, b);
  print(st[n - 1][a + b - 2] * CC(a + b - 2, a - 1));
}
#include "YRS/aa/main.hpp"