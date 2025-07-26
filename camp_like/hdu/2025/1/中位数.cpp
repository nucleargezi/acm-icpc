#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

#define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  fenw<monoid_add<int>> seg(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    seg.build(n);
    for (int k = i; k < n; ++k) {
      seg.multiply(a[k], 1);
      if (k - i & 1) continue;
      ans += 1ll * (i + 1) * (k + 1) * seg.kth(k - i >> 1);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"