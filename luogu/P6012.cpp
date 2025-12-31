#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(N, K);
  VEC(mint, a, N);
  vc<vc<mint>> f(N);
  FOR(i, N) f[i] = {1, a[i]};
  print(conv_all(f)[K]);
}
#include "YRS/aa/main.hpp"