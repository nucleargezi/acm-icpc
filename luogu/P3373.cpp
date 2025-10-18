// #include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_affine.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

void before() {}

// #define tests
using mint = dmint;
void Yorisou() {
  LL(n, q, mod);
  mint::set_mod(mod);
  VEC(mint, a, n);
  lazy_seg<a_monoid_sum_affine<mint>> seg(a);
  FOR(q) {
    LL(op, l, r);
    --l;
    if (op == 1) {
      LL(x);
      seg.apply(l, r, {x, 0});
    } else if (op == 2) {
      LL(x);
      seg.apply(l, r, {1, x});
    } else {
      UL(seg.prod(l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"