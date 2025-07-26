#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/his_max_add_assign.hpp"

// #define tests
using mono = a_monoid_his_max_add_assign<ll>;
constexpr ll tag = mono::Monoid_A::Tag;
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  lazy_seg<mono> seg(n, [&](int i) { iroha pair{a[i], a[i]}; });
  FOR(q) {
    LL(op, l, r);
    --l, --op;
    if (op == 0) {
      LL(x);
      seg.apply(l, r, {x, tag, MAX(x, 0ll), tag});
    } else if (op == 1) {
      LL(x);
      seg.apply(l, r, {0, x, 0, x});
    } else if (op == 2) {
      print("{}", seg.prod(l, r).first);
    } else {
      print("{}", seg.prod(l, r).second);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"