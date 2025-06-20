#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"
#include "MeIoN_Lib/graph/Apck/tree_diameter.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  graph g(n);
  FOR(i, m) {
    LL(x, y);
    --x, --y;
    g.add(x, y);
  }
  g.build();
  meion [cnt, id] = scc_id(g);
  dsu uf(cnt);
  FOR(i, n) for (meion &&e : g[i]) {
    if (id[i] != id[e.to]) {
      uf.merge(id[i], id[e.to]);
    }
  }
  vector<vector<int>> ps(cnt);
  FOR(i, n) ps[uf[id[i]]] += i;
  ll ans = n - cnt;
  for (vector v : uf.get_group()) {
    if (len(v) == 1) continue;
    meion u = v;
    unique(u);
    graph ng(len(v));
    meion p = ps[uf[v[0]]];
    for (int x : p) {
      int ix = lower_bound(u, id[x]);
      for (meion &&e : g[x]) {
        if (id[e.to] != id[x]) {
          int iy = lower_bound(u, id[e.to]);
          ng.add(ix, iy);
        }
      }
    }
    ng.build();
    meion [in, ou] = ng.deg_array_inout();
    meion lf = std::ranges::count(in, 1);
    ans += len(v) - (tree_diameter(ng).first - 1 + lf);
  }
  ans += uf.get_comp() - 1;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"