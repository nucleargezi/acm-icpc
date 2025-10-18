#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec_tree2.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  graph g(n);
  g.read_tree();

  centroid_dec_tree<monoid_add<ll>, graph<>> seg(g);
  while (q--) {
    CH(op);
    if (op == 'M') {
      INT(x, d, w);
      --x;
      seg.apply(x, d + 1, w);
    } else {
      INT(x);
      --x;
      UL(seg.get(x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"