#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/PR/primtable.hpp"
#include "YRS/math/poly/convolution.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
Z t = primtable(1'000'000);
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vector<int> c = pre_sum(a);
  const int sz = QMAX(c) + 1;
  vector<mint> f(sz), g(sz);
  for (int x : c) f[x] = 1;
  for (int x : t) {
    if (x >= sz) break;
    g[x] = 1;
  }
  Z r = convolution(f, g);
  ll s = 0;
  FOR(i, sz) if (f[i].val) s += r[i].val;
  print(s);
}
#include "YRS/Z_H/main.hpp"