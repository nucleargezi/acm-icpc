#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/beats_sum_minmax_chminmax.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  beats_sum_minmax_chminmax<ll> seg(a);
  while (q--) {
    INT(op, l, r);
    if (op == 0) {
      LL(x);
      seg.chmin(l, r, x);
    } else if (op == 1) {
      LL(x);
      seg.chmax(l, r, x);
    } else if (op == 2) {
      LL(x);
      seg.add(l, r, x);
    } else {
      meion [s, min, max] = seg.prod(l, r);
      UL(s);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"