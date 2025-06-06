#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/maxidx_add.hpp"
#include "MeIoN_Lib/ds/chtholly/chtholly_fast.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  vector<PII> c(n + 1 << 1);
  FOR(i, (n + 1 << 1)) c[i].second = i;
  chtholly_fast<T3<int>> ch(n, {0, 0, 0});
  FOR(i, n) {
    ch.set(i, i + 1, {i, i + 1, a[i]});
    ++c[a[i]].first;
  }
  lazy_seg<a_monoid_max_idx_add<int>> seg(c);
  meion [x, y] = seg.prod_all();
  UL(y, x);
  FOR(m) {
    LL(l, r, d);
    --l;
    vector<pair<bool, T3<int>>> go{{true, {l, r, d}}};
    ch.enumerate_range(l, r, [&](int l, int r, T3<int> dat) {
      meion [L, R, od] = dat;
      if (r < R) {
        go.emplace_back(false, T3<int>{r, R, od + r - L});
      }
      if (L < l) {
        go.emplace_back(false, T3<int>{L, l, od});
      }
      if (l > L) {
        seg.apply(od, od + r - L, -1);
        seg.apply(od, od + l - L, 1);
      } else {
        seg.apply(od, od + r - l, -1);
      }
    });
    for (meion [upd, dat] : go) {
      meion [l, r, d] = dat;
      ch.set(l, r, {l, r, d});
      if (upd) seg.apply(d, d + r - l, 1);
    }
    meion [x, y] = seg.prod_all();
    UL(y, x);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"