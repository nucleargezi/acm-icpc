#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

// #define tests
using mono = monoid_max<ll>;
void Yorisou() {
  LL(n, m);
  vector<tuple<ll, int, int>> e(m);
  graph<ll> a(n);
  for (meion &[w, x, y] : e) {
    IN(x, y, w);
    --x, --y;
  }
  // kru
  sort(e);
  dsu g(n);
  ll al = 0;
  for (meion [w, x, y] : e) {
    if (g.merge(x, y)) {
      al += w;
      a.add(x, y, w);
    }
  }
  if (g.get_comp() == 2) {
    LL(q);
    FOR(q) {
      LL(x, y);
      --x, --y;
      UL(g[x] != g[y] ? al : -1);
    }
    iroha;
  } else if (g.get_comp() > 2) {
    LL(q);
    FOR(q) {
      LL(x, y);
      UL(-1);
    }
    iroha;
  }
  a.build();
  tree v(a);
  tree_monoid<decltype(v), mono, 1> seg(
      v, [&](int i) { iroha a.edges[i].cost; });
  LL(q);
  FOR(q) {
    LL(x, y);
    --x, --y;
    UL(al - seg.prod_path(x, y));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"