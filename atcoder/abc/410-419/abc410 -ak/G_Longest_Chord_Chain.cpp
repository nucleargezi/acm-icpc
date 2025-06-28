#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  for (meion &[l, r] : a) {
    if (l < r) swap(l, r);
    --l, --r;
  }
  sort(a);
  Seg<monoid_max<ll>> seg(n << 1);
  vector<int> dp(n);
  FOR(i, n) {
    meion [r, l] = a[i];
    seg.set(l, dp[i] = seg.prod(l, r + 1) + 1);
  }
  FOR(i, n) {
    meion [r, l] = a[i];
    dp[i] += seg.prod(r, n << 1);
  }
  UL(QMAX(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"