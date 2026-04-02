#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
using P = pair<mint, mint>;
using monoid = monoid_affine<mint>;
void Yorisou() {
  LL(n, q);
  VEC(P, a, n);
  Seg<monoid_affine<mint>> seg(a);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(p, c, d);
      seg.set(p, {c, d});
    } else {
      LL(l, r, x);
      UL(monoid::eval(seg.prod(l, r), x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"