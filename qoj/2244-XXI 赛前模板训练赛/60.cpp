#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/lct/LCT.hpp"
#include "MeIoN_Lib/ds/lct/node_commute_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/xor.hpp"

// #define tests
using LCT = Link_Cut_Tree<lct_node_commutative_monoid<monoid_xor<int>>>;
using np = LCT::np;
void Yorisou() {
  LL(n, q);
  LCT lct(n);
  FOR(i, n) {
    INT(x);
    lct.set(i, x);
  }
  FOR(q) {
    LL(op, x, y);
    --x, --y;
    if (op == 0) {
      lct.evert(x);
      print("{}", lct.get_root(y) == x ? lct.prod_path(x, y) : -1);
    } else if (op == 1) {
      lct.evert(x);
      if (lct.get_root(y) != x) {
        lct.link(x, y);
      }
    } else if (op == 2) {
      lct.evert(x);
      if (lct.get_fa(y) == x) {
        lct.cut(x, y);
      }
    } else {
      lct.set(x, y + 1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"