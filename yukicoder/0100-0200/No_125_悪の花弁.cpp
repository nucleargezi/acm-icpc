#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(K);
  VEC(int, a, K);
  int N = SUM(a);

  vc<mint> c(N + 1);
  vc<u8> vis(N + 1);
  Z f = [&](int d) -> mint {
    if (vis[d]) return c[d];
    int L = N / d;
    vis[d] = 1;
    for (int x : a) if (x % L != 0) return 0;
    mint s = fac(d);
    for (int x : a) s *= ifac(x / L);
    return c[d] = s;
  };

  mint s = 0;
  FOR(i, N - 1) s += f(gcd(i, N));
  print(s / N);
}
#include "YRS/aa/main.hpp"