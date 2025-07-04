#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/seg/dual_seg.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/monoid/max_sub_array_sum.hpp"

#define tests
using mono = monoid_max_subarray_sum<int>;
using dat = mono::X;
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  FOR(i, n) --a[i];

  vector<vector<PII>> go(n);
  FOR(i, n) go[a[i]].emplace_back(0, i);
  FOR(i, q) {
    LL(idx, x);
    --idx, --x;
    go[a[idx]].emplace_back(i, idx);
    a[idx] = x;
    go[a[idx]].emplace_back(i, idx);
  }
  FOR(i, n) go[a[i]].emplace_back(q, i);

  static constexpr dat bas[]{{0, 0, -1, 0}, {1, 1, 1, 1}};
  dual_seg<monoid_max<int>> res(q, [](int i) { iroha 0; });
  vector<u8> f(n);
  meion ele = [&](int i) { iroha bas[f[i]]; };
  Seg<mono> seg(n, ele);
  FOR(i, n) {
    FOR(k, len(go[i])) {
      meion [l, idx] = go[i][k];
      f[idx] ^= 1;
      seg.set(idx, ele(idx));
      int r = (k == len(go[i]) - 1 ? q : go[i][k + 1].first);
      if (l < r) res.apply(l, r, seg.prod_all().mx);
    }
  }
  vector<int> ans = res.get_all();
  FOR(i, q) ans[i] >>= 1;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"