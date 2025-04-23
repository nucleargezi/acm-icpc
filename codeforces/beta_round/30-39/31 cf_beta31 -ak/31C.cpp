#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  lazy_seg<a_monoid_max_add<ll>> seg(1'000'001, [](int i) { iroha 0; });
  FOR(i, n) {
    seg.apply(a[i].first, a[i].second, 1);
  }
  vector<ll> ans;
  FOR(i, n) {
    seg.apply(a[i].first, a[i].second, -1);
    if (seg.prod_all() < 2) ans += i + 1;
    seg.apply(a[i].first, a[i].second, 1);
  }
  UL(len(ans));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"