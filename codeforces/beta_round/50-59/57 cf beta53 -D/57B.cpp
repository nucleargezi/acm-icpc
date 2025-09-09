#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/seg/lazy_seg_base.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"

// #define tests
void Yorisou() {
  INT(n, m, k);
  lazy_seg<a_monoid_sum_add<ll>> seg(n + 1);
  FOR(m) {
    INT(l, r, c);
    --l;
    seg.apply(l, c - 1);
    seg.apply(r, 1 - c);
    seg.apply(l, r, 1);
    seg.apply(r, l - r);
  }
  vector ar = pre_sum<false>(seg.get_all());
  ll ans = 0;
  FOR(k) {
    INT(x);
    ans += ar[--x];
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"