#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/a_monoid/max_set_add.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"

// #define tests
using mono = a_monoid_max_set_add<int>;
using tag = mono::MA;
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree<true>();
  tree v(g);
  lazy_tree_monoid<decltype(v), mono, true> seg(
      v, [&](int i) { return g.edges[i].cost; });
  
  while (true) {
    STR(op);
    if (op == "Max") {
      INT(x, y);
      --x, --y;
      print(seg.prod_path(x, y));
    } else if (op == "Change") {
      INT(k, w);
      --k;
      seg.set(g.edges[k].id, w);
    } else if (op == "Cover") {
      INT(x, y, w);
      --x, --y;
      seg.apply_path(x, y, tag::make_set(w));
    } else if (op == "Add") {
      INT(x, y, w);
      --x, --y;
      seg.apply_path(x, y, tag::make_add(w));
    } else {
      break;
    }
  }
}
#include "YRS/Z_H/main.hpp"