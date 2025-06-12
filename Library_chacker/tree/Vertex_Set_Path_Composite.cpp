#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
using PMM = pair<mint, mint>;
using mono = monoid_affine<mint>;
void Yorisou() {
  LL(n, q);
  VEC(PMM, a, n);
  graph g(n);
  g.read_tree<0, 0>();
  tree v(g);
  tree_monoid<decltype(v), mono> seg(v, a);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, a, b);
      seg.set(p, {a, b});
    } else {
      LL(x, y, v);
      UL(mono::eval(seg.prod_path(x, y), v));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"