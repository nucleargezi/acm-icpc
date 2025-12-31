#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1004535809>;
void Yorisou() {
  INT(N, M, s);
  VEC(mint, f, M + 1);
  FOR(i, M + 1) f[i] *= fact_inv<mint>(i);
  vc<mint> g(M + 1);
  FOR(i, M + 1) g[i] = mint(i & 1 ? -1 : 1) * fact_inv<mint>(i);
  f = convolution(f, g);
  FOR(i, M + 1) f[i] *= fact<mint>(i);
  mint ans = 0;
  FOR(k, M + 1) if (N - s * k >= 0) {
    ans += f[k] * C<mint>(M, k) * fact_inv<mint>(s).pow(k) *
           mint(M - k).pow(N - s * k) * fact_inv<mint>(N - s * k);
  }
  print(ans * fact<mint>(N));
}
#include "YRS/aa/main.hpp"