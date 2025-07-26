#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/block_cut_tree.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  graph g(n);
  g.read_graph(m);
  meion v = block_cut(g);
  meion in = v.deg_array();
  vector<int> ans;
  FOR(i, n) if (in[i] >= 2) ans += i + 1;
  print("{}\n{}", len(ans), ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"