#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  dsu g(N);
  FOR(i, N) g.merge(i, a[i] - 1);
  vc<vc<int>> s = g.get_group();
  map<int, int> mp;
  for (Z &v : s) if ((len(v) & 1) == 0) ++mp[len(v)];
  for (Z [x, y] : mp) if (y & 1) return No();
  Yes();
}
#include "YRS/aa/main.hpp"