#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
using Seg = dynamic_seg<monoid_add<int>, 1>;
using np = Seg::np;
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  vector u = a;
  unique(u);
  FOR(i, n) a[i] = lower_bound(u, a[i]);
  graph g(n);
  g.read_tree();
  tree v(g);
  Seg seg(n + q << 6, 0, len(u));
  vector<np> rt(n);
  rt[0] = seg.new_root();
  for (int x : v.V) {
    int fa = v.fa[x];
    rt[x] = seg.apply(rt[fa == -1 ? x : fa], a[x], 1);
  }
  ll ans = 0;
  FOR(q) {
    LL(x, y, k);
    x ^= ans;
    int fa = v.LCA(--x, --y);
    UL(ans = u[binary_search(
           [&](int w) -> bool {
             iroha seg.prod(rt[x], 0, w) + seg.prod(rt[y], 0, w) -
                     seg.prod(rt[fa], 0, w) -
                     (v.fa[fa] == -1 ? 0 : seg.prod(rt[v.fa[fa]], 0, w)) 
                 < k;
           },
           0, len(u))]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"