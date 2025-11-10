#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/dsu.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/max_idx.hpp"

// #define tests
using LCT = LCT_monoid_commute<monoid_max_idx<int>>;
void Yorisou() {
  INT(N, M);
  vector<T4<int>> e(M);
  LCT lct(N + M);
  FOR(i, N + M) lct.a[i].mx = {-1, i};
  for (Z &[x, y, a, b] : e) {
    IN(x, y, a, b);
    --x, --y;
    swap(x, a), swap(y, b);
  }
  sort(e);
  FOR(i, M) {
    Z [a, b, x, y] = e[i];
    lct.a[i + N].mx.fi = b;
  }
  dsu g(N);
  int ans = inf<int>;
  FOR(i, M) {
    Z [a, b, x, y] = e[i];
    if (g[x] != g[y]) {
      lct.link(i + N, x);
      lct.link(i + N, y);
      g.merge(x, y);
    } else {
      Z [max, id] = lct.prod(x, y);
      if (max > b) {
        Z [_, __, xx, yy] = e[id - N];
        lct.cut(id, xx);
        lct.cut(id, yy);
        lct.link(x, i + N);
        lct.link(y, i + N);
      }
    }
    if (g[0] == g[N - 1]) chmin(ans, a + lct.prod(0, N - 1).fi);
  }
  print(ans == inf<int> ? -1 : ans);
}
#include "YRS/Z_H/main.hpp"