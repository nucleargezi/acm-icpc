#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dominator_tree.hpp"

// #define tests
void Yorisou() {
  INT(n, m, s);
  graph<bool, 1> g(n);
  g.read_graph<0, 0>(m);
  meion res = dominator_tree(g, s);
  res[s] = s;
  UL(res);
}
#include "MeIoN_Lib/Z_H/main.hpp"