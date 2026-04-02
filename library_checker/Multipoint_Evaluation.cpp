#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/po/multipoint.hpp"

#define tests 0
#define fl 1
#define DB 100
using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(mint, f, N);
  VEC(mint, q, Q);
  print(multi_eval(f, q));
}
#include "YRS/aa/main.hpp"