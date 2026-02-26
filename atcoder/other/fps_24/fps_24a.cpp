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
  INT(D, N);
  fps f(max(N + 1, 7));
  f[1] = f[3] = f[4] = f[6] = 1;
  print(fps_pow(f, D)[N]);
}
#include "YRS/aa/main.hpp"