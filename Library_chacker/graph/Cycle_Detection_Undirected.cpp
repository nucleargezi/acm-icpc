#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/find_cycle_directed.hpp" 

// #define tests
void Yorisou() {
  INT(n, m);
  graph<bool, 0> g(n);
  g.read_graph<0, 0>(m);
  meion [vs, es] = find_cycle_undirected(g);
  if (es.empty()) iroha UL(-1);
  UL(len(vs));
  UL(vs);
  UL(es);
}
#include "MeIoN_Lib/Z_H/main.hpp"