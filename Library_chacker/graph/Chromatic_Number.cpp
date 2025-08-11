#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/min_color.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  graph g(n);
  g.read_graph<0, 0>(m);
  UL(chromatic_number(g));
}
#include "MeIoN_Lib/Z_H/main.hpp"