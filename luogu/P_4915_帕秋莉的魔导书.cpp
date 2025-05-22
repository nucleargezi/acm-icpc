#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_dynamic_seg.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
using RE = long double;
using Seg = lazy_dynamic_seg<a_monoid_sum_add<ll>, 0, ll>;
void Yorisou() {
  LL(n, q);
  ll L = -inf<int>, R = inf<int> + 1ll;
  Seg seg(n + q << 5, L, R);
  Seg::np rt = seg.new_root();
  FOR(n) {
    LL(x, y);
    seg.apply(rt, x, R, y);
  }
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(l, r);
      UL((RE)seg.prod(rt, l, r + 1) / (r - l + 1));
    } else {
      LL(x, y);
      seg.apply(rt, x, R, y);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"