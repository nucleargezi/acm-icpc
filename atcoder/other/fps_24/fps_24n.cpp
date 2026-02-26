#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/prod_of_one_minus_xn.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> coef(N);
  FOR(i, N) coef[i] = min<ll>(N + 1, ll(i + 1) * (a[i] + 1));
  fps f = prod_of_one_minus_xn<mint>(coef, N);
  FOR(i, N) coef[i] = i + 1;
  fps g = prod_of_inv_one_minus_xn<mint>(coef, N);
  mint s = 0;
  FOR(i, N + 1) s += f[i] * g[N - i];
  print(s);
}
#include "YRS/aa/main.hpp"