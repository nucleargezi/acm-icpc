#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, M);
  fps f(M + 1), p(M + 1);
  fill(all(p), 1);
  FOR(i, 1, M + 1) if (i & 1) f[i] = 1;
  f = fps_pow(f, N - 1);
  f = p * f;
  sh(f, M + 1);
  print(SUM<mint>(f) * fac(N));
}
#include "YRS/aa/main.hpp"