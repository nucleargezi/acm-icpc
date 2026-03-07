#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/inc_mst.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T4<int>, es, M);
  for (Z &[x, y, a, b] : es) {
    --x, --y;
    swap(x, a), swap(y, b);
  }
  sort(es);
  dsu g(N);
  inc_mst<int> ds(N);
  int s = inf<int>;
  FOR(i, M) {
    Z [a, b, x, y] = es[i];
    g.merge(x, y);
    ds.add(x, y, {b, i});
    if (g[0] == g[N - 1]) chmin(s, a + ds.path_max(0, N - 1).fi);
  }
  print(s == inf<int> ? -1 : s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"