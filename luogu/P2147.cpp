#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/LCT.hpp"

void before() {}

// #define tests
using LCT = Link_Cut_Tree<LCT_Node_Base>;
void Yorisou() {
  LL(n, q);
  LCT seg(n);
  FOR(q) {
    S(op);
    LL(x, y);
    --x, --y;
    if (op[0] == 'C') {
      seg.link(x, y);
    } else if (op[0] == 'D') {
      seg.cut(x, y);
    } else {
      Yes(seg.get_root(x) == seg.get_root(y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"