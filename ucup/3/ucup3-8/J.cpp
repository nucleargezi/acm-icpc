#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/dsu.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/ds/monoid/max.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  dsu g(N);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e);

  ll ans = 0;
  graph v(N), vv(N);
  vector<T3<int>> es;
  for (Z [w, x, y] : e) {
    int ww = 0;
    if (g.merge(x, y)) {
      ans += w;
      if (~w & 1) swap(w, ww);
      v.add(x, y, w);
      vv.add(x, y, ww);
    } else {
      es.ep(x, y, w);
    }
  }
  if (g.count() != 1) return print(-1, -1);

  ll other = inf<ll>;
  v.build(), vv.build();
  tree tr(v), rt(vv);
  tree_monoid_ST<decltype(tr), monoid_max<int>, true> 
      segO(tr, [&](int i) { return v.edges[i].cost; }),
      segE(rt, [&](int i) { return vv.edges[i].cost; });
  for (Z [x, y, w] : es) {
    if (w & 1) {
      int v = segE.prod_path(x, y);
      if (v) chmin(other, ans - v + w);
    } else {
      int v = segO.prod_path(x, y);
      if (v) chmin(other, ans - v + w);
    }
  }
  if (other == inf<ll>) other = -1;
  if (ans & 1) swap(ans, other);
  print(ans, other);
}
#include "YRS/Z_H/main.hpp"