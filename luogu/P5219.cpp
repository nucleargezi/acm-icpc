#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/aa/def.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
mint f(int N, int M) {
  vc<mint> f(2 * N - 1);
  FOR(i, 1, M + 1) f[i] = ifac(i - 1);
  return fps_pow(f, N)[2 * N - 2] * fac(N - 2);
}
void Yorisou() {
  INT(N, M);
  print(f(N, M) - f(N, M - 1));
}
#include "YRS/aa/main.hpp"