#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  graph g(n);
  FOR(i, 1, n) {
    LL(x);
    g.add(a[--x], a[i]);
  }
  g.build();
  tree v(g, 0);
  vector<int> ans(n + 1);
  for (meion &&e : g[0]) {
    chmax(ans[0], v.subtree_size(e.to));
  }
  vector<u8> vis(n + 1);
  FOR(i, n - 1) {
    int x = i;
    while (x != -1 and not vis[x]) {
      vis[x] = 1;
      x = v.fa[x];
    }
    if (not vis[i + 1]) ans[i + 1] = n - v.subtree_size(i + 1);
  }
  ans[n] = n;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"