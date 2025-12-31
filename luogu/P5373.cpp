#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/comp.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  b.resize(N + 1);
  print(comp(a, b));
}
#include "YRS/aa/main.hpp"