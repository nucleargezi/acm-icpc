#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  LL(q);
  vector<ll> dat(n, 1);
  tree_monoid<decltype(v), monoid_add<ll>> seg(v, dat);
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x, w);
      seg.apply(--x, w);
    } else {
      LL(eid);
      meion [x, y, w, id] = g.edges[--eid];
      if (v.deep[x] > v.deep[y]) std::swap(x, y);
      ll v = seg.prod_subtree(y);
      UL(ABS(v + v - seg.prod_all()));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"