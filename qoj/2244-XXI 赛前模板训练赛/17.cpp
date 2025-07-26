#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/dominator_tree.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  constexpr int N = 5'000'00;
  graph<int, 1> g(N);
  g.read_graph(m);
  vector fa = get_fa(g, 0);
  graph<int, 1> v(N);
  FOR(i, 1, n) v.add(fa[i], i);
  v.build();
  tree t(v);
  vector<int> ans(n);
  FOR(i, n) ans[i] = t.subtree_size(i);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"