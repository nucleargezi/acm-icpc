#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/crt.hpp"
#include "YRS/pr/f/line_con_1.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, M, D, tx, ty, sx, sy, vx, vy);
  ll d = gcd(vx, vy);
  vx /= d, vy /= d, D *= d;
  ll f[]{tx, tx, 2 * N - tx, 2 * N - tx}, g[]{ty, 2 * M - ty, ty, 2 * M - ty};
  FOR(i, 4) {
    int tx = f[i], ty = g[i];
    vc<ll> a, mds;
    Z [x, mod] = line_con_1(vx, tx - sx, 2 * N);
    if (x == -1) continue;
    a.ep(x);
    mds.ep(mod);
    tie(x, mod) = line_con_1(vy, ty - sy, 2 * M);
    if (x == -1) continue;
    a.ep(x);
    mds.ep(mod);
    ll st = crt_reduce(a, mds);
    if (st != -1 and st <= D) return print("Hit");
  }
  print("Miss");
}
#include "YRS/aa/main.hpp"