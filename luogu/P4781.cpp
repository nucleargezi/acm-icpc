#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/lag.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  vc<mint> x(N), y(N);
  FOR(i, N) IN(x[i], y[i]);
  print(lag_inte<mint>(x, y, K));
}
#include "YRS/aa/main.hpp"