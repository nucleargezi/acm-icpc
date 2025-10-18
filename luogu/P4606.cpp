#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/graph/Apck/block_cut_tree.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/ds/static_range_group.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.read_graph(M);
  Z ng = block_cut(g);
  tree v(ng, 0);
  tree_monoid_ST<decltype(v), monoid_add<int>, false, static_range_group> seg(
      v, [&](int i) -> int { return i < N; });
  INT(Q);
  FOR(Q) {
    INT(sz);
    VEC(int, a, sz);
    for (int &x : a) --x;
    sort(a, [&](int x, int y) -> bool { return v.L[x] < v.L[y]; });
    int ans = 0;
    FOR(i, sz) {
      int x = a[i], y = a[(i + 1) % sz];
      int f = v.LCA(x, y);
      ans += seg.prod_path(x, f) - (f < N);
      ans += seg.prod_path(y, f) - (f < N);
    }
    print(ans / 2 - sz + (v.LCA(a[0], a.back()) < N));
  }
}
#include "YRS/Z_H/main.hpp"