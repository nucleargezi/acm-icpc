#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  int n, m;
  while (IN(n, m)) {
    int t = 0;
    vector<vector<T3<int>>> e(n);
    vector<map<int, int>> I(n);
    FOR(m) {
      INT(x, y, c, w);
      --x, --y;
      e[x].emplace_back(c, y, w);
      e[y].emplace_back(c, x, w);
      I[x][c], I[y][c];
    }
    FOR(i, n) for (meion &[x, y] : I[i]) y = t++;
    graph<ll, 1> g(t);
    FOR(i, n) for (int pc = -1, pt; meion [c, t] : I[i]) {
      if (pc == -1) {
        pc = c, pt = t;
        continue;
      }
      g.add(pt, t, c - pc);
      g.add(t, pt, c - pc);
      pc = c, pt = t;
    }
    FOR(i, n) for (meion [c, t, w] : e[i]) {
      g.add(I[i][c], I[t][c], w);
    }
    g.build();
    vector<int> st;
    for (meion [c, f] : I[0]) {
      st.emplace_back(f);
    }
    meion dis = dijkstra(g, st).first;
    ll ans = inf<ll>;
    for (meion [c, t] : I[n - 1]) {
      chmin(ans, dis[t]);
    }
    print("{}", ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"