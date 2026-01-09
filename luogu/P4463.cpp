#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint_d.hpp"
#include "YRS/po/lag.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = dmint;
void Yorisou() {
  INT(K, N, P);
  mint::set_mod(P);
  vc<mint> f(1);
  f[0] = 1;
  vc<mint> go;
  FOR(i, 1, N + N + ceil(N, 2)) {
    if (len(f) < N + 1) f.ep();
    FOR_R(k, len(f) - 1) f[k + 1] += f[k] * i;
    go.ep(len(f) > N ? f[N] : 0);
  }
  print(lag_inte_iota<mint>(go, K - 1) * fac(N));
}
#include "YRS/aa/main.hpp"