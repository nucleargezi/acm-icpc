#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  INT(N, M, H);
  VEC(int , h, N);
  Z id = [&](int x, int y) -> int { return x * (H + 1) + y; };
  graph<ll, 1> g(N * (H + 1));
  FOR(M) {
    INT(x, y, w);
    --x, --y;
    if (h[x] > h[y]) swap(x, y);
    int d = h[y] - h[x];
    FOR(i, H + 1) {
      if (i + d > H) break;
      g.add(id(x, i), id(y, i + d), w);
    }
    if (h[x] != h[y]) FOR(i, H + 1) g.add(id(y, i), id(x, 0), w);
    else FOR(i, H + 1) g.add(id(y, i), id(x, i), w);
  }
  g.build();
  Z dis = dijkstra(g, 0).fi;
  vector<ll> ans(N, inf<ll>);
  FOR(i, N) FOR(h, H + 1) {
    if (dis[id(i, h)] == inf<ll>) continue;
    chmin(ans[i], dis[id(i, h)]);
  }
  FOR(i, N) if (ans[i] == inf<ll>) ans[i] = -1;
  ans.erase(ans.begin());
  print(ans);
}
#include "YRS/Z_H/main.hpp"