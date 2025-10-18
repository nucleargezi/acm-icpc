#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec_tree.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  VEC(ll, dat, n);
  graph g(n);
  g.read_tree();

  centroid_dec_tree<monoid_add<ll>, graph<>> seg(g, dat);
  ll ans = 0;
  while (q--) {
    INT(op, x, k);
    x ^= ans, k ^= ans;
    --x;
    if (op == 0) {
      UL(ans = seg.prod(x, k));
    } else {
      seg.set(x, k);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"