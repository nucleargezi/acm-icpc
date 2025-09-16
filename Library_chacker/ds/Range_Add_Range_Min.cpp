#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/lazy_seg_base.hpp"
#include "YRS/ds/a_monoid/min_add.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  lazy_seg<a_monoid_min_add<ll>> seg(a);
  FOR(Q) {
    INT(op, l, r);
    if (op == 0) {
      INT(x);
      seg.apply(l, r, x);
    } else {
      print(seg.prod(l, r));
    }
  }
}
#include "YRS/Z_H/main.hpp"