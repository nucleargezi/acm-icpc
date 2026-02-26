#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/ofps.hpp"

using mint = M99;
using fps = vc<mint>;
using ofps = online_fps_ctx<mint>;
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  STR(s);
  FOR(i, N) s[i] -= '0';
  fps f(N);
  FOR(i, N) if (s[i]) f[i] = ifac(i) * mint(2).inv();

  ofps ctx;
  Z A = ctx.val(f);
  Z F = ctx.var();
  F.set((A * F * F + 1).inte());
  f = F.ke(N + 1);
  FOR(i, 1, N + 1) print(f[i] * fac(i));
}
#include "YRS/aa/main.hpp"