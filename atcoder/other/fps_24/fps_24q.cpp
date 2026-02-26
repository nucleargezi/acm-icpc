#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/sum_of_pow.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, M, K);
  VEC(mint, a, N);
  VEC(mint, b, M);
  fps c = sum_of_pow(a, K), d = sum_of_pow(b, K);
  FOR(i, K + 1) c[i] *= ifac(i);
  FOR(i, K + 1) d[i] *= ifac(i);
  c = convolution(c, d);
  mint in = mint(1) / N / M;
  FOR(i, 1, K + 1) print(c[i] * fac(i) * in);
}
#include "YRS/aa/main.hpp"