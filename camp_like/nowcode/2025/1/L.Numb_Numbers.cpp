#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  vector ra = a, f = a;
  vector<PLL> quis;
  FOR(q) {
    LL(p, ad);
    --p;
    quis.emplace_back(a[p], a[p] + ad);
    a[p] += ad;
    f += a[p];
  }
  unique(f);
  const int N = len(f);
  meion get = [&](ll x) { iroha lower_bound(f, x); };
  
  a = ra;
  FOR(i, n) a[i] = get(a[i]);
  for (meion &[f, t] : quis) {
    f = get(f), t = get(t);
  }

  Seg<monoid_add<int>> seg(N);
  FOR(i, n) seg.multiply(a[i], 1);
  for (meion [f, t] : quis) {
    seg.multiply(f, -1);
    seg.multiply(t, 1);
    int r = seg.max_right([&](ll s) { iroha s <= ceil(n, 2); }, 0);
    print("{}", seg.prod(0, r));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"