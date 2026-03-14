#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_dynamic_seg.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, q);
  lazy_dynamic_seg<a_monoid_sum_affine<mint>, 0> seg(q << 5, 0, n);
  meion rt = seg.new_root();
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(l, r, c, d);
      seg.apply(rt, l, r, {c, d});
    } else {
      LL(l, r);
      UL(seg.prod(rt, l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"