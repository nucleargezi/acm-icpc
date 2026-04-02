#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  graph g(n);
  g.read_tree<0, 0>();
  tree v(g);
  tree_monoid<decltype(v), monoid_add<ll>> seg(v, a);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, x);
      seg.multiply(p, x);
    } else {
      LL(x, y);
      UL(seg.prod_path(x, y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"