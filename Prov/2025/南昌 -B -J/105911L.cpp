#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/minmax.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  graph g(n);
  g.read_tree();
  tree v(g);
  vector<PII> a(n);
  int t = 0;
  FOR(i, n) a[i] = {v.L[i], v.L[i]};
  Seg<monoid_minmax<int>> L(a), R(n);
  vector<vector<T3<int>>> quis(n);
  vector<int> ans(q);
  FOR(i, q) {
    LL(l, r, p);
    --l, --p;
    quis[p].emplace_back(l, r, i);
  }
  meion &V = v.V;
  meion f = [&](int a, int b, int c) { iroha v.meet(a, b, c); };
  FOR(i, n) {
    int p = V[i];
    L.set(p, {inf<int>, -inf<int>});
    R.set(p, a[p]);
    for (meion [l, r, id] : quis[p]) {
      meion [a, b] = R.prod(l, r);
      meion [c, d] = L.prod(l, r);
      if (a == inf<int>) {
        ans[id] = f(V[c], V[d], p) + 1;
      } else if (c == inf<int>) {
        ans[id] = f(V[a], V[b], p) + 1;
      } else {
        ans[id] = f(f(V[a], V[b], p), f(V[c], V[d], p), p) + 1;
      }
    }
  }
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"