#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = modint<201314>;
using mono = a_monoid_sum_add<mint>;
void Yorisou() {
  INT(N, Q);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    g.add(f, i);
  }
  g.build();
  tree v(g);
  lazy_tree_monoid<decltype(v), mono> seg(v);
  vector<T4<int>> quis;
  vector<mint> ans(Q);
  FOR(i, Q) {
    INT(l, r, z);
    ++r;
    quis.ep(l, z, i, 0);
    quis.ep(r, z, i, 1);
  }
  sort(quis);
  for (int t = 0; Z [l, z, i, op] : quis) {
    while (t < l) seg.apply_path(0, t, 1), ++t;
    ans[i] += seg.prod_path(0, z) * (op ? 1 : -1);
  }
  for (Z x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"