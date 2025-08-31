#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bellman_ford.hpp"
#include "YRS/graph/Apck/bfs.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  graph<ll, 1> g(n + 1);
  VEC(PII, e, m);
  vector<int> vis(n), siv(n);
  for (meion &[x, y] : e) --x, --y;
  graph<int, 1> ng(n);
  for (meion [x, y] : e) {
    ng.add(x, y);
  }
  ng.build();
  graph<int, 1> pg(n);
  for (meion [x, y] : e) {
    pg.add(y, x);
  }
  pg.build();
  meion DIS = bfs(ng, 0).first;
  meion SID = bfs(pg, n - 1).first;
  if (DIS[n - 1] == inf<int>) UL(-1), exit(0);
  FOR(i, n) if (DIS[i] != inf<int> and SID[i] != inf<int>) vis[i] = 1;
  for (meion [x, y] : e) {
    if (not vis[x] or not vis[y]) continue;
    g.add(x, y, 9);
    g.add(y, x, -1);
  }
  FOR(i, n) g.add(n, i, 0);
  g.build();
  meion dis = bellman_ford(g, n).first;
  if (dis.empty()) iroha UL(-1);
  UL(n, m);
  for (meion [x, y] : e) {
    UL(x + 1, y + 1, (vis[x] and vis[y]) ? dis[y] - dis[x] : 1);
  }
}
#include "YRS/Z_H/main.hpp"