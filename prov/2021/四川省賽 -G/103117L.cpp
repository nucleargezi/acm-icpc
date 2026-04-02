#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs1.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, q);
  vector<vector<int>> st(100);
  FOR(i, n) {
    LL(w);
    st[--w] += i;
  }
  graph g(n);
  g.read_graph(m);
  vector<vector<int>> dis;
  FOR(w, 100) {
    dis.emplace_back(st[w].empty() ? vector(n, inf<int>) : bfs1(g, st[w]).first);
  }
  FOR(i, 99) FOR(k, n) chmin(dis[i + 1][k], dis[i][k]);
  FOR(i, q) {
    LL(p, w);
    --p, --w;
    UL(dis[w][p] == inf<int> ? -1 : dis[w][p]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"