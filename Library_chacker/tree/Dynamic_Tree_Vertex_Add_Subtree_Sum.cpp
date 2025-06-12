#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/lct/LCT.hpp"
#include "MeIoN_Lib/ds/lct/node_commute_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<ll>;
using node = lct_node_commutative_monoid<mono, 1>;
using LCT = Link_Cut_Tree<node>;
void Yorisou() {
  LL(n, q);
  LCT seg(n);
  VEC(ll, a, n);
  FOR(i, n) {
    seg.set(i, a[i]);
  }
  FOR(n - 1) {
    LL(x, y);
    seg.link(x, y);
  }
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(a, b, c, d);
      seg.cut(a, b);
      seg.link(c, d);
    } else if (op == 1) {
      LL(p, x);
      a[p] += x;
      seg.set(p, a[p]);
    } else {
      LL(x, fa);
      UL(seg.prod_subtree(x, fa));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"