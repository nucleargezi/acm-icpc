#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, c, n - 1);
  VEC(ll, a, n - 1);
  a.insert(a.begin(), 0);
  c.insert(c.begin(), 0);
  Seg<monoid_max<int>> vis(n);
  ll ans = 0;
  ll s = 0;
  FOR(i, n) s += not not a[i];
  vis.set(0, 1);
  meion f = [&]() {
    FOR(i, n) {
      if (a[i] and vis.get(i) != 1) {
        if (i - c[i] <= 0) {
          vis.set(i, 1);
          ++ans;
          --s;
        } else {
          if (vis.prod(i - c[i], i) > 0) {
            vis.set(i, 1);
            ++ans;
            --s;
          }
        }
      }
    }
  };
  f();
  while (s) {
    Seg<monoid_min<int>> dp(n);
    FOR(i, n) {
      if (vis.get(i) == 1) {
        dp.set(i, 0);
      } else {
        ll x = dp.prod(MAX(0ll, i - c[i]), i) + 1;
        if (a[i]) {
          ans += x;
          vis.set(i, 1);
          --s;
          break;
        } else {
          dp.set(i, x);
        }
      }
    }
    f();
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"