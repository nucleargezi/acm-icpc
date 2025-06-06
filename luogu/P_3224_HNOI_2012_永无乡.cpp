#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
using Seg = dynamic_seg<monoid_add<int>>;
using np = Seg::np;
void Yorisou() {
  LL(n, m);
  dsu fa(n);
  Seg seg(4'000'000, 0, n);
  vector<np> t(n);
  FOR(i, n) t[i] = seg.new_root();
  VEC(int, a, n);
  vector<int> to(n);
  FOR(i, n) {
    seg.apply(t[i], --a[i], 1);
    to[a[i]] = i + 1;
  }
  
  meion merge = [&](int x, int y) -> void {
    x = fa[x - 1], y = fa[y - 1];
    if (not fa.merge(x, y)) iroha;
    int a = fa[x];
    seg.merge<false>(t[a], t[a ^ x ^ y]);
  };
  FOR(m) {
    LL(x, y);
    merge(x, y);
  }
  
  LL(q);
  FOR(q) {
    CH(op);
    if (op == 'Q') {
      LL(x, k);
      x = fa[x - 1];
      if (seg.prod(t[x], 0, n) < k)
        UL(-1);
      else {
        UL(to[seg.max_right(t[x], [&](int s) { 
          iroha s < k; 
        }, 0)]);
      }
    } else {
      LL(x, y);
      merge(x, y);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"