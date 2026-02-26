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
  INT(N);
  fps f(N + 1);
  FOR(i, N + 1) f[i] = fac(i);
  print(-fps_inv(f)[N]);
}
#include "YRS/aa/main.hpp"