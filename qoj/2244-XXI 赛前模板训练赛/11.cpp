#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/brige.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  graph g(n);
  g.read_graph(m);
  meion vis = brige(g);
  FOR(i, m) if (vis[i]) {
    meion &&e = g.edges[i];
    print("{} {}", e.f + 1, e.to + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"