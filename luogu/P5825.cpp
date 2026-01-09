#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/convolution.hpp"
#include "YRS/mod/powertable.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  vc<mint> f(N + 2);
  FOR(i, N + 2) f[i] = CC(N + 1, i);
  FOR(i, N + 2) if (i & 1) f[i] = -f[i];
  vc<mint> g = power_table_2<mint>(N, N + 2);
  g.erase(g.begin());
  f = convolution(f, g);
  f.resize(N + 1);
  f[N] = 0;
  print(f);
}
#include "YRS/aa/main.hpp"