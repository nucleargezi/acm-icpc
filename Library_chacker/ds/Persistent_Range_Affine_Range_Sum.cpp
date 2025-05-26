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
  lazy_dynamic_seg<a_monoid_sum_affine<mint>, 1> seg(1'000'000'0, 0, n);
  vector<decltype(seg)::np> rt(q + 1);
  VEC(mint, a, n);
  rt[0] = seg.new_node(a);
  FOR(i, 1, q + 1) {
    LL(op, k);
    ++k;
    if (op == 0) {
      LL(l, r, b, c);
      rt[i] = seg.apply(rt[k], l, r, {b, c});
    } else if (op == 1) {
      LL(s, l, r);
      ++s;
      rt[i] = seg.copy_interval(rt[k], rt[s], l, r, {1, 0});
    } else {
      LL(l, r);
      UL(seg.prod(rt[i] = rt[k], l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"