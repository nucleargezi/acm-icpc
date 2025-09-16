#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/lazy_seg_base.hpp"
#include "YRS/ds/a_monoid/max_add.hpp"

#define tests
void Yorisou() {
  INT(N, K);
  VEC(PII, a, N);
  FOR(i, N) --a[i].FI;

  lazy_seg<a_monoid_max_add<int>> seg(N, [&](int)  { return 0; });
  int p = 0;
  int ans = 0;
  FOR(i, N) {
    Z [l, r] = a[i];
    seg.apply(l, r, 1);
    while (seg.prod_all() > K) {
      Z [l, r] = a[p];
      seg.apply(l, r, -1);
      ++p;
    }
    chmax(ans, i - p + 1);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"