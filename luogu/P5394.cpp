#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/FFP_conv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  print(FFP_conv(a, b));
}
#include "YRS/aa/main.hpp"