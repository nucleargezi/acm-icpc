#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
using mint = dmint;
void Yorisou() {
  LL(n, q, rt, mod);
  mint::set_mod(mod);
  --rt;
  VEC(mint, a, n);
  graph g(n);
  g.read_tree();
  tree v(g, rt);
  Lazy_Tree_Monoid<decltype(v), a_monoid_sum_add<mint>> seg(v, a);
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x, y, w);
      seg.apply_path(--x, --y, w);
    } else if (op == 2) {
      LL(x, y);
      UL(seg.prod_path(--x, --y));
    } else if (op == 3) {
      LL(x, w);
      seg.apply_subtree(--x, w);
    } else {
      LL(x);
      UL(seg.prod_subtree(--x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"