#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
using monoid = monoid_affine<mint>;
void Yorisou() {
  LL(n, q);
  dynamic_seg<monoid_affine<mint>, false> seg(q << 5, 0, n);
  meion rt = seg.new_root();
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, c, d);
      seg.set(rt, p, {c, d});
    } else {
      LL(l, r, x);
      UL(monoid::eval(seg.prod(rt, l, r), x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"