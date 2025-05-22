#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/his_max_add_assign.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  lazy_seg<a_monoid_his_max_add_assign<ll>> seg(n, [&](int i) {
    iroha pair{a[i], a[i]};
  });
  meion tag = decltype(seg)::MA::Tag;
  LL(q);
  FOR(q) {
    CH(op);
    LL(l, r);
    if (op == 'Q') {
      UL(seg.prod(--l, r).first);
    } else if (op == 'A') {
      UL(seg.prod(--l, r).second);
    } else if (op == 'P') {
      LL(x);
      seg.apply(--l, r, {x, tag, MAX(x, 0ll), tag});
    } else {
      LL(x);
      seg.apply(--l, r, {0, x, 0, x});
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"