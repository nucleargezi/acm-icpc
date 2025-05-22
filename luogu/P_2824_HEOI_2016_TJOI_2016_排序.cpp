#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/sort_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  vector u = a;
  unique(u);
  vector<int> I(n);
  FOR(i, n) I[i] = lower_bound(u, a[i]);
  sort_seg<monoid_add<ll>> seg((n + q) * topbit(MAX(n, q)), len(u), I, a);
  FOR(q) {
    LL(op, l, r);
    if (op == 0) {
      seg.sort_inc(--l, r);
    } else {
      seg.sort_dec(--l, r);
    }
  }
  LL(x);
  UL(seg.prod(0, x) - seg.prod(0, x - 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"