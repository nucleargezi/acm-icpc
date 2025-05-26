#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  Seg<monoid_add<ll>> seg(a);
  FOR(q) {
    LL(op, x, y);
    if (op == 0) {
      seg.apply(x, y);
    } else {
      UL(seg.prod(x, y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"