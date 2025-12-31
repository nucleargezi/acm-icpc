#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_sqrt.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
vc<mint> sq(vc<mint> f, mint y, mint x, int d) {
  int N = len(f);
  mint c = mint(1) / y;
  vc<mint> g(N - d);
  FOR(i, N - d) g[i] = f[d + i] * c;
  g = fps_sq(g);
  g.resize(N);
  FOR(i, N) g[i] *= x;
  FOR_R(i, N) {
    if (i >= d / 2) g[i] = g[i - d / 2];
    else g[i] = 0;
  }
  return g;
}
vc<mint> stupit_sqrt(vc<mint> f) {
  int N = len(f), d = N;
  if (f[0] == mint(1)) return fps_sqrt(f);
  FOR_R(i, N) if (f[i] != mint(0)) d = i;
  if (d == N) return f;
  if (d & 1) return {};
  mint y = f[d], x = mod_sqrt<mint>(y);
  if (x * x != y) return {};
  return min(sq(f, y, x, d), sq(f, y, -x, d));
}
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(stupit_sqrt(f));
}
#include "YRS/aa/main.hpp"