#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  ll N = 0;
  STR(s);
  for (char c : s) {
    c -= '0';
    N = N * 10 + c;
    N %= mint::get_mod() - 1;
  }
  vc<mint> f(3), g(3);
  f[0] = 1, f[1] = -1, f[2] = -1;
  g[0] = 1, g[1] = -2, g[2] = -1;
  print(coef_of_rational_fps(f, g, N));
}
#include "YRS/aa/main.hpp"