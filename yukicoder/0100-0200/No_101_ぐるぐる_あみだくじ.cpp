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
  INT(N, M);
  vc<int> I(N);
  iota(all(I), 0);
  FOR(M) {
    INT(x, y);
    --x, --y;
    swap(I[x], I[y]);
  }
  dsu g(N);
  FOR(i, N) g.merge(i, I[i]);
  ll s = 1;
  for (vc<int> v : g.get_group()) {
    s = lcm(s, len(v));
  }
  print(s);
}
#include "YRS/aa/main.hpp"