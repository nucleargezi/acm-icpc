#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q); 
  VEC(ll, a, n);
  using Seg = dynamic_seg<monoid_add<ll>, 1>;
  Seg seg(n + q << 5, 0, n);
  vector<Seg::np> rt(q + 1);
  rt[0] = seg.new_node(a);
  FOR(i, q) {
    LL(ver, op);
    if (op == 1) {
      LL(p, c);
      rt[i + 1] = seg.set(rt[ver], --p, c);
    } else {
      LL(p);
      rt[i + 1] = rt[ver];
      UL(seg.prod(rt[i + 1], p - 1, p));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"