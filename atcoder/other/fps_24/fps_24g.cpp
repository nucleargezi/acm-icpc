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
  INT(N, M, L);
  vc<mint> f(N + 1);
  f[0] = 1;
  Z ad = [&](int t) { FOR(i, t, N + 1) f[i] += f[i - t]; };
  Z rm = [&](int t) { FOR_R(i, t, N + 1) f[i] -= f[i - t]; };
  FOR(i, 1, M + 1) {
    ad(i);
    if (i >= L) print(f[N]), rm(i - L + 1);
  }
}
#include "YRS/aa/main.hpp"