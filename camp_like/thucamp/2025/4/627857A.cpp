#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/minmax_add.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  a = pre_sum<false>(a);
  ll x = a[n - 1] / n;
  FOR(i, n) a[i] -= (i + 1) * x;
  lazy_seg<a_monoid_minmax_add<ll>> seg(n, [&](int i)  {
    iroha PLL{a[i], a[i]};
  });
  FOR(q) {
    LL(l, r, x);
    if (l > r) swap(l, r);
    else x = -x;
    seg.apply(l - 1, r - 1, x);
    meion [a, b] = seg.prod_all();
    UL(std::max(std::abs(a), std::abs(b)));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"