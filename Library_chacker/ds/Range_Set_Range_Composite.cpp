#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/range_assign_seg.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
using mono = monoid_affine<mint>;
void Yorisou() {
  LL(n, q);
  VEC(mono::X, a, n);
  range_assign_seg<mono> seg(a);
  while (q--) {
    INT(op, l, r);
    if (op == 0) {
      INT(c, d);
      seg.assign(l, r, {c, d});
    } else {
      INT(x);
      UL(mono::eval(seg.prod(l, r), x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"