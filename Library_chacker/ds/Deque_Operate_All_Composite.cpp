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
  Seg<mono> seg(n << 1);
  ll l = n, r = n;
  FOR(n) {
    LL(op);
    if (op == 0) {
      LL(x, y);
      seg.set(--l, {x, y});
    } else if (op == 1) {
      LL(x, y);
      seg.set(r++, {x, y});
    } else if (op == 2) {
      ++l;
    } else if (op == 3) {
      --r;
    } else {
      LL(x);
      UL(mono::eval(seg.prod(l, r), x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"