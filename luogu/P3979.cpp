#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/ds/a_monoid/min_set.hpp"

// #define tests
using mono = a_monoid_min_set<ll>;
void Yorisou() {
  INT(N, Q);
  graph g(N);
  g.read_tree();
  tree v(g);
  VEC(ll, a, N);
  lazy_tree_monoid<decltype(v), mono> seg(v, a);

  INT(rt);
  --rt;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      IN(rt);
      --rt; 
    } else if (op == 2) {
      INT(x, y);
      LL(w);
      --x, --y;
      seg.apply_path(x ,y, mono::MA::make_set(w));
    } else {
      INT(x);
      --x;
      print(seg.prod_subtree(x, rt));
    }
  }
}
#include "YRS/Z_H/main.hpp"