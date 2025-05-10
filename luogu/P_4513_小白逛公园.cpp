#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max_sub_array_sum.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  Seg<monoid_max_subarray_sum<ll>> seg(n, [&](int i) {
    iroha a[i];
  });
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(l, r);
      if (l > r) std::swap(l, r);
      --l;
      UL(seg.prod(l, r).mx);
    } else {
      LL(p, x);
      seg.set(--p, x);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"