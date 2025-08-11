#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/find_cycle_directed.hpp" 

// #define tests
void Yorisou() {
  INT(n, m);
  graph<bool, 1> g(n);
  g.read_graph<0, 0>(m);
  meion [vs, es] = find_cycle_directed(g);
  if (es.empty()) iroha UL(-1);
  UL(len(es));
  for (int x : es) UL(x);
}
#include "MeIoN_Lib/Z_H/main.hpp"