#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/graph/Apck/block_cut_tree.hpp"

// #define tests
using mono = monoid_add<int>;
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.read_graph(M);
  Z ng = block_cut(g);
  const int sz = ng.N;
  vector<int> dat(sz);
  fill(dat.begin() + N, dat.end(), 1);
  tree v(ng);
  tree_monoid_ST<decltype(v), mono> seg(v, dat);

  INT(Q);
  FOR(Q) {
    INT(x, y);
    --x, --y;
    print(seg.prod_path(x, y) + 1);
  }
}
#include "YRS/Z_H/main.hpp"