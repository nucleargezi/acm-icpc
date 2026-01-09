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
template <typename mint>
mint sol(int N, int l, int r, vc<int> a) {
}
void Yorisou() {
  INT(N, l, r);
  VEC(int, a, N);
  vc<mint> f = {mint(1), mint(-1)};
  f.resize(r + 1);
  f = fps_pow(f, N);
  FOR(i, N) ++a[i];
  vc<mint> g = prod_of_one_minus_xn<mint>(a, r + 1);
  f = fps_div(g, f);
  mint s = 0;
  FOR(i, l, r + 1) s += f[i];
  print(s);
}
#include "YRS/aa/main.hpp"