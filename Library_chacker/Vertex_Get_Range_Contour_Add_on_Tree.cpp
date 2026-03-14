#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec_tree2.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  VEC(ll, dat, n);
  graph g(n);
  g.read_tree<0, 0>();

  centroid_dec_tree<monoid_add<ll>, graph<>> seg(g, dat);
  while (q--) {
    INT(op, x);
    debug();
    if (op == 0) {
      INT(l, r, k);
      seg.apply(x, l, r, k);
    } else {
      UL(seg.get(x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"