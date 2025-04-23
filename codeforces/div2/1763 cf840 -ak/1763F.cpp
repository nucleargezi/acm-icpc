#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/block_cut_tree.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  graph<ll> g(n);
  g.read_graph(m);
  meion ng = block_cut(g);
  tree v(ng);
  n = v.n;
  vector<int> w(n);
  for (meion &&e : g.edges) {
    w[v.jump(e.f, e.to, 1)] += 1;
  }
  FOR(i, n) w[i] = w[i] == 1 ? 0 : w[i];
  tree_monoid<decltype(v), monoid_add<int>, false> seg(v, w);
  LL(q);
  FOR(q) {
    LL(x, y);
    UL(seg.prod_path(--x, --y));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"