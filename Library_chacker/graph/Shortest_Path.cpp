#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  INT(n, m, s, t);
  graph<ll, 1> g(n);
  g.read_graph<1, 0>(m);
  meion [dis, fa] = dijkstra(g, s);
  if (dis[t] == inf<ll>) iroha UL(-1);
  vector<int> path;
  int x = t;
  while (x != -1) path.emplace_back(x), x = fa[x];
  reverse(path);
  UL(dis[t], len(path) - 1);
  FOR(i, len(path) - 1) {
    UL(path[i], path[i + 1]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"