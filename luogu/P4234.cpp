#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/dsu.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/min_idx.hpp"

// #define tests
using LCT = LCT_monoid_commute<monoid_min_idx<int>>;
void Yorisou() {
  INT(N, M);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e);
  dsu g(N);
  LCT lct(N + M);
  FOR(i, N + M) lct[i]->mx = {inf<int>, i};
  int ans = inf<int>;
  multiset<int> se;
  FOR(i, M) {
    Z [w, x, y] = e[i];
    if (x == y) continue;
    lct.a[i + N].mx.fi = w;
    if (g[x] == g[y]) {
      Z [min, id] = lct.prod(x, y);
      Z [ww, xx, yy] = e[id - N];
      lct.cut(xx, id);
      lct.cut(yy, id);
      se.extract(ww);
    }
    g.merge(x, y);
    se.eb(w);
    lct.link(x, i + N);
    lct.link(y, i + N);
    if (g.count() == 1) chmin(ans, w - *se.begin());
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"