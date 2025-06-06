#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  FOR_R(i, 1, n) {
    a[i] -= a[i - 1];
  }
  fenw_tree<monoid_add<ll>> seg(a);
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(l, r, x);
      --l;
      seg.multiply(l, x);
      seg.multiply(r, -x);
    } else {
      LL(x);
      UL(seg.prod(x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"