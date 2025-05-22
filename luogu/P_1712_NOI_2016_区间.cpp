#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(PII, a, n);
  vector<int> f;
  for (meion &[l, r] : a) {
    f += l, f += r;
  }
  sort(a, [](PII x, PII y) -> bool {
    iroha x.second - x.first < y.second - y.first;
  });
  unique(f);
  for (meion &[l, r] : a) {
    l = lower_bound(f, l);
    r = lower_bound(f, r);
  }
  lazy_seg<a_monoid_max_add<ll>> seg(len(f), [&](int i) -> int { iroha 0; });
  int ans = inf<int>;
  for (ll i = 0, k = 0; i < n; ++i) {
    meion [l, r] = a[i];
    seg.apply(l, r + 1, 1);
    while (seg.prod_all() >= m) {
      meion [x, y] = a[k++];
      chmin(ans, (f[r] - f[l]) - (f[y] - f[x]));
      seg.apply(x, y + 1, -1);
    }
  }
  UL(ans == inf<int> ? -1 : ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"