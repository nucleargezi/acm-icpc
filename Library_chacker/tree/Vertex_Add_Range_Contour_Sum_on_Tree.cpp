#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec_tree.hpp"
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
    if (op == 0) {
      LL(k);
      seg.multiply(x, k);
    } else {
      INT(l, r);
      UL(seg.prod(x, l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"