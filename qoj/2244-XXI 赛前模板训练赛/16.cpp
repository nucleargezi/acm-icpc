#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  LL(n, m, s, t);
  --s, --t;
  graph g(n);
  g.read_graph<1>(m);
  print("{}", dijkstra(g, s).first[t]);
}
#include "MeIoN_Lib/Z_H/main.hpp"