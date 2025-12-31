#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint_d.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = dmint;
mint sq(mint x) { return x * x; }
void Yorisou() {
  INT(N, M, P);
  mint::set_mod(P);
  if (M == 1) {
    ll s = ll(N) * (N + 1) / 2 % P;
    s = s * s % P;
    return print(s);
  }
  mint in = mint(M).inv();
  int L = (N + 1) / 2 + 1, R = N / 2 + 1;
  vc<mint> f(N + 10), g(N + 10);
  mint x = 1, a = 0, b = 0;
  FOR(i, 1, L) {
    f[i] = f[i - 1] + x;
    g[i] = g[i - 1] + x * (i * 2 - 1);
    x *= in;
    a += 2 * f[i], b += 2 * g[i] - 2 * f[i] * f[i];
    if ((N & 1) and i == L - 1) a -= f[i], b += f[i] * f[i] - g[i];
  }
  x = 1;
  FOR(i, 1, R) {
    x *= in;
    f[i] = f[i - 1] + x;
    g[i] = g[i - 1] + x * (i * 2 - 1);
    a += 2 * f[i], b += 2 * g[i] - 2 * f[i] * f[i];
    if (not(N & 1) and i == R - 1) a -= f[i], b += f[i] * f[i] - g[i];
  }
  print((a * a + b).val);
}
#include "YRS/Z_H/main.hpp"