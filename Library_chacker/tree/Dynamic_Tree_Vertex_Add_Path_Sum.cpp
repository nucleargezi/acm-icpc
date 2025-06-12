#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/lct/LCT.hpp"
#include "MeIoN_Lib/ds/lct/node_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<ll>;
using node = lct_node_monoid<mono>;
using LCT = Link_Cut_Tree<node>;
void Yorisou() {
  LL(n, q);
  LCT seg(n);
  FOR(i, n) {
    LL(x);
    seg.set(i, x);
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
      seg.set(p, seg.prod_path(p, p) + x);
    } else {
      LL(x, y);
      UL(seg.prod_path(x, y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"