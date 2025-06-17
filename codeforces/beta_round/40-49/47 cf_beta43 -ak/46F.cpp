#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
using bs = bitset<1500>;
void Yorisou() {
  LL(n, m, K);
  graph<bool> g(n);
  g.read_graph(m);
  meion f = [&]() {
    vector vis(n, bs{});
    vector<vector<string>> s(n);
    FOR(K) {
      S(t);
      LL(x, sz);
      s[--x] += t;
      FOR(sz) {
        LL(y);
        vis[x][--y] = 1;
      }
    }
    dsu u(n);
    while (1) {
      bool f = 0;
      for (meion &&e : g.edges) {
        int x = u[e.f], y = u[e.to];
        if (x == y) continue;
        if (vis[x][e.id] or vis[y][e.id]) {
          f = 1;
          u.merge(x, y);
          vis[u[x]] = vis[x] | vis[y];
        }
      }
      if (not f) break;
    }
    map<string, pair<bs, bs>> m;
    FOR(i, n) {
      if (s[i].empty()) continue;
      bs x{}, y{};
      FOR(k, n) x[k] = u[i] == u[k];
      y = vis[u[i]];
      for (meion &s : s[i]) m[s] = {x, y};
    }
    iroha m;
  };
  YES(f() == f());
}
#include "MeIoN_Lib/Z_H/main.hpp"