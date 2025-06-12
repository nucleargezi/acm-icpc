#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/lct/LCT.hpp"
#include "MeIoN_Lib/ds/lct/node_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
using mono = monoid_affine<mint>;
using node = lct_node_monoid<mono>;
using LCT = Link_Cut_Tree<node>;
void Yorisou() {
  LL(n, q);
  LCT seg(n);
  FOR(i, n) {
    LL(a, b);
    seg.set(i, {a, b});
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
      LL(p, a, b);
      seg.set(p, {a, b});
    } else {
      LL(x, y, t);
      UL(mono::eval(seg.prod_path(x, y), t));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"