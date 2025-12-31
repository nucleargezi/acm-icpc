#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/multipoint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, a, r);
  VEC(mint, f, N);
  print(multi_inte_geoseq<mint>(f, a, r));
}
#include "YRS/aa/main.hpp"