#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  dsu g(n);
  vector<vector<PLL>> v(n);
  FOR(m) {
    LL(x, y, w);
    --x, --y;
    g.merge(x, y);
    v[x].emplace_back(y, w);
  }
  if (g[0] != g[n - 1]) iroha UL(-1);
  vector vis(n, bitset<1024>{});
  queue<PII> q;
  vis[0][0] = 1;
  q.emplace_back(0, 0);
  while (not q.empty()) {
    meion [n, x] = q.pop();
    for (meion [t, w] : v[n]) {
      if (not vis[t][w ^ x]) {
        vis[t][w ^ x] = 1;
        q.emplace_back(t, w ^ x);
      }
    }
  }
  int ans = -1;
  FOR_R(i, 1024) if (vis[n -1 ][i]) ans = i;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"