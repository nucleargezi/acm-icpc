#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
using mono = monoid_affine<mint>;
void Yorisou() {
  LL(n);
  Seg<mono> seg(n);
  ll l = 0, r = 0;
  FOR(n) {
    LL(op);
    if (op == 0) {
      LL(x, y);
      seg.set(r++, {x, y});
    } else if (op == 1) {
      ++l;
    } else {
      LL(x);
      UL(mono::eval(seg.prod(l, r), x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"