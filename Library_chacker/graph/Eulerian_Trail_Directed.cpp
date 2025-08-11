#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/euler_walk.hpp"

#define tests
void Yorisou() {
  INT(n, m);
  graph<bool, 1> g(n);
  g.read_graph<0, 0>(m);
  meion [vs, es] = euler_walk(g);
  if (vs.empty()) iroha No();
  Yes();
  UL(vs);
  UL(es);
}
#include "MeIoN_Lib/Z_H/main.hpp"