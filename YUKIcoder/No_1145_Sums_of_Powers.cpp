#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/sum_of_pow.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  VEC(mint, a, N);
  vc<mint> r = sum_of_pow(a, K);
  vc<mint> g(N, 1);
  assert(r == sum_of_pow_coef(a, g, K));
  r.erase(r.begin());
  print(r);
}
#include "YRS/aa/main.hpp"