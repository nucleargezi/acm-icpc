#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/crt.hpp"
#include "YRS/pr/f/line_con_1.hpp"
#include "YRS/nt/bigint/big.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  using ll = bigint;
  LL(N, M, D, tx, ty, sx, sy, vx, vy);
  ll d = gcd(vx, vy);
  vx /= d, vy /= d, D *= d;
  ll f[]{tx, tx, N * 2 - tx, N * 2 - tx}, g[]{ty, M * 2 - ty, ty, M * 2 - ty};
  FOR(i, 4) {
    ll tx = f[i], ty = g[i];
    vc<ll> a, mds;
    Z [x, mod] = line_con_1(vx, tx - sx, N * 2);
    if (x == -1) continue;
    a.ep(x);
    mds.ep(mod);
    tie(x, mod) = line_con_1(vy, ty - sy, M * 2);
    if (x == -1) continue;
    a.ep(x);
    mds.ep(mod);
    ll st = crt_reduce(a, mds);
    if (st != -1 and st <= D) return print("Hit");
  }
  print("Miss");
}
#include "YRS/aa/main.hpp"