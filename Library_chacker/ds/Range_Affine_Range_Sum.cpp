#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, q);
  VEC(mint, a, n);
  lazy_seg<a_monoid_sum_affine<mint>> seg(a);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(l, r, c, d);
      seg.apply(l, r, {c, d});
    } else {
      LL(l, r);
      UL(seg.prod(l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"