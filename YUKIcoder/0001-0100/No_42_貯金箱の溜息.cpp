#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/lag.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'000 + 9>;
using fps = vc<mint>;
void Yorisou() {
  int N = 3000;
  vc<mint> f(N);
  f[0] = 1;
  for (int x : {1, 5, 10, 50, 100, 500}) {
    FOR(i, N - x) f[i + x] += f[i];
  }
  vc<vc<mint>> s(500);
  FOR(i, 500) FOR(k, 6) s[i].ep(f[i + k * 500]);

  INT(Q);
  FOR(Q) {
    LL(x);
    int r = x % 500;
    x /= 500;
    print(lag_inte_iota(s[r], mint(x)));
  }
}
#include "YRS/aa/main.hpp"