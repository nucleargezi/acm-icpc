#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/max_independent_set.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  graph g(n);
  g.read_graph<0, 0>(m);
  meion ans = max_independent_set<40>(g);
  UL(len(ans));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"