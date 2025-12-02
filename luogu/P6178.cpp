#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/line/det.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int mod = 1'000'000'000 + 7;
void f(int &x) {
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
}
void Yorisou() {
  INT(N, M, T);
  vector g(N - 1, vc<int>(N - 1));
  FOR(M) {
    INT(x, y, w);
    x -= 2, y -= 2;
    if (y >= 0) f(g[y][y] += w);
    if (x >= 0) if (not T) f(g[x][x] += w);
    if (x >= 0 and y >= 0) {
      f(g[x][y] -= w);
      if (not T) f(g[y][x] -= w);
    }
  }
  print(det(g, mod));
}
#include "YRS/Z_H/main.hpp"