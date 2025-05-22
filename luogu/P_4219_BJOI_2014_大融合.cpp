#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/LCT.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
using LCT = Link_Cut_Tree<lct_node_commutative_monoid<monoid_add<int>, 1>>;
void Yorisou() {
  LL(n, q);
  LCT seg(n);
  FOR(i, n) seg.set(i, 1);
  FOR(q) {
    CH(op);
    LL(x, y);
    --x, --y;
    if (op == 'A') {
      seg.link(x, y);
    } else {
      UL(seg.prod_subtree(y, x) * seg.prod_subtree(x, y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"