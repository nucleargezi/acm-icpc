#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

#define tests
void Yorisou() {
  LL(n, s, x);
  VEC(ll, a, n);
  map<ll, vector<int>> m;
  vector c = pre_sum(a);
  FOR(i, n + 1) {
    m[c[i]] += i;
  }
  vector<T4<ll>> rg;
  Seg<monoid_max<ll>> seg(a);
  FOR(i, n) if (a[i] == x) {
    int l = seg.min_left([&](ll mx) {
      iroha mx < x;
    }, i);
    int r = seg.max_right([&](ll mx) {
      iroha mx <= x;
    }, i);
    rg.emplace_back(l, i, i + 1, r);
  }
  ll ans = 0;
  for (meion [l0, l1, r0, r1] : rg) {
    FOR(i, l0, l1 + 1) {
      ans += upper_bound(m[c[i] + s], r1) - lower_bound(m[c[i] + s], r0);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"