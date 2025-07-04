#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"

// #define tests
void Yorisou() {
  int n, q;
  while (IN(n, q)) {
    vector<int> a(n);
    FOR(i, n) {
      CH(c);
      a[i] = c == '(' ? 1 : -1;
    }
    Seg<monoid_min<int>> seg(pre_sum<false>(a));
    FOR(q) {
      INT(l, r);
      --l, --r;
      if (l > r) swap(l, r);
      if (a[l] == 1 and a[r] == -1)
        Yes(seg.prod(l, r) > 1);
      else
        Yes();
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"