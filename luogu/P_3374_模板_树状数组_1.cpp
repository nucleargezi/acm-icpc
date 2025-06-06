#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  fenw_tree<monoid_add<ll>> seg(a);
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x, v);
      --x;
      seg.multiply(x, v);
    } else {
      LL(l, r);
      --l;
      UL(seg.prod(l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"