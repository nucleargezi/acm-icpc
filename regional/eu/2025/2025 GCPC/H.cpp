#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/bfs.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph<int, 1> g(N);
  g.read_graph(M);
  INT(s, ss);
  --s, --ss;
  Z dis = bfs(g, s).fi, sid = bfs(g, ss).fi;
  FOR(i, N) if (dis[i] != inf<int> and sid[i] != inf<int>) return yes(), print(i + 1);
  no();
}
#include "YRS/Z_H/main.hpp"