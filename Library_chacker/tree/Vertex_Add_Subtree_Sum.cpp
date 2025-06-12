#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  graph g(n);
  FOR(i, 1, n) {
    LL(fa);
    g.add(fa, i);
  }
  g.build();
  tree v(g);
  tree_monoid<decltype(v), monoid_add<ll>> seg(v, a);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, x);
      seg.multiply(p, x);
    } else {
      LL(x);
      UL(seg.prod_subtree(x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"