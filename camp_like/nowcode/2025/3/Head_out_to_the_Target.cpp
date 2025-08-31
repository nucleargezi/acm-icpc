#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/tree_haiki/LCA.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  vector<vector<int>> v(n);
  graph G(n);
  FOR(i, 1, n) {
    LL(fa);
    --fa;
    G.add(fa, i);
    v[fa].emplace_back(i);
  }
  G.build();
  tree tr(G);
  LCA<21> lca(v, 0);
  meion &g = lca.up;
  vector<T3<int>> quis;
  FOR(q) {
    LL(x, l, r);
    --x, --l;
    quis.emplace_back(l, r, x);
  }
  sort(quis);
  vector<u8> vis(n);
  vis[0] = 1;
  for (meion [l, r, x] : quis) {
    if (vis[x]) iroha UL(l + 1);
    int y = x;
    for (int i = 20; i > -1; --i) {
      if (vis[g[y][i]]) continue;
      y = g[y][i];
    }
    int d = tr.dist(tr.fa[y], x);
    if (d <= r - l) iroha UL(l + d);
    int go = tr.jump(tr.fa[y], x, r - l);
    while (go != y) vis[go] = 1, go = tr.fa[go];
    vis[y] = 1;
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"