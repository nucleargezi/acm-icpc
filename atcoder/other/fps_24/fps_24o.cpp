#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/pr/primtable.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N);
  fps f(2 * N - 1), g(f);
  vc<int> pt = primtable(N);
  for (int x : pt) f[x] = ifac(x - 1);
  g[1] = 1;
  for (int x : pt) g[x + 1] = ifac(x);
  print((f * fps_pow(g, N - 1))[2 * N - 2] * fac(N - 2));
}
#include "YRS/aa/main.hpp"