#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/count_cyc_3.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  graph g(n);
  g.read_graph(m);
  UL(count_cyc_3(g));
}
#include "MeIoN_Lib/Z_H/main.hpp"