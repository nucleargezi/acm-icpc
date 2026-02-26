#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/fps_sqrt.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, K);
  VEC(mint, f, N + 1);
  fps s = fps_pow(
      fps_log(fps {2} + f - fps {f[0]} - fps_exp(inte(fps_inv(fps_sqrt(f))))) +
          fps {1},
      K);
  sh(s, N + 1);
  print(diff(s));
}
#include "YRS/aa/main.hpp"