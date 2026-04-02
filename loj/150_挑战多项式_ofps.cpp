#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_sqrt.hpp"
#include "YRS/po/ofps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
using ofps = online_fps_ctx<mint>;
void Yorisou() {
  INT(N, K);
  VEC(mint, f, N + 1);
  fps s = fps_exp(inte(fps_inv(fps_sqrt(f))));

  ofps X;
  Z a = X.val(f);
  Z b = X.val(s);
  Z r = ((2 + a - f[0] - b).log() + 1).pow(K);
  f = r.ke(N + 1);
  print(diff(f));
}
#include "YRS/aa/main.hpp"