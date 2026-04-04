#include "YRS/all.hpp"

using fps = vc<ll>;
using cf = const fps &;
vc<ll> ml(cf f, cf g) {
  int N = si(f), M = si(g);
  fps c(N);
  FOR(i, N) FOR(k, M) if (i + k < N) c[i + k] += f[i] * g[k];
  return c;
}
void Yorisou() {
  INT(N);
  vc<ll> f(6 * N + 1), g(N + 1, 1);
  f[0] = 1;
  FOR(8) f = ml(f, g);
  print(f.back());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"