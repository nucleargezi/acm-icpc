#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/hungarian.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  retsu<ll> g(N, N, -inf<ll> >> 10);
  FOR(M) {
    INT(x, y, w);
    --x, --y;
    g[y][x] = w;
  }
  Z [s, mat, x, y] = hungarian<ll, false>(g);
  print(s);
  for (int &x : mat) ++x;
  print(mat);
}
#include "YRS/Z_H/main.hpp"