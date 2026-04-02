#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(q);
  VEC(PLL, a, q);
  vector<ll> f;
  for (meion [l, r] : a) {
    f += l, f += r;
  }
  unique(f);
  const int n = len(f);
  vector<PLL> v(n + n - 1);
  FOR(i, len(v)) v[i] = {i, 1};
  FOR(i, n - 1) {
    v[i << 1 | 1].second = f[i + 1] - f[i] - 1;
  }
  for (meion [l, r] : a) {
    std::swap(v[lower_bound(f, l) << 1], v[lower_bound(f, r) << 1]);
  }
  ll ans = 0;
  Seg<monoid_add<ll>> seg(n << 1);
  FOR(i, n + n - 1) {
    ans += seg.prod(v[i].first + 1, n + n) * v[i].second;
    seg.apply(v[i].first, v[i].second);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"