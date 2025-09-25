#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/scc.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph<int, true> g(N);
  g.read_graph(M);
  Z [cnt, id] = scc_id(g);
  vector<int> sz(cnt);
  FOR(i, N) ++sz[id[i]];
  print(QMAX(sz));
  if (cnt == 1) return print(0);
  Z ng = scc_dag(g, cnt, id);
  Z [I, O] = ng.deg_array_inout();
  int x = 0, y = 0;
  FOR(i, cnt) {
    x += I[i] == 0;
    y += O[i] == 0;
  }
  print(std::max(x, y));
}
#include "YRS/Z_H/main.hpp"