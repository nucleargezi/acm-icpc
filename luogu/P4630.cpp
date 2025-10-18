#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/block_cut_tree.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.read_graph(M);
  Z ng = block_cut(g);
  const int sz = ng.N;
  ll ans = 0;
  vector<int> siz(sz), vl(sz);
  FOR(i, N) {
    --vl[i];
    for (Z &&e : ng[i]) ++vl[e.to];
  }
  dsu u(sz);
  for (Z &e : ng.edges) {
    u.merge(e.f, e.to);
  }
  vector<int> tot(sz);
  FOR(i, N) ++tot[u[i]];
  vector<char> vis(sz);
  Z f = [&](Z &f, int n) -> void {
    siz[n] = n < N;
    vis[n] = 1;
    for (Z &&e : ng[n]) {
      if (vis[e.to]) continue;
      f(f, e.to);
      ans += 1ll * siz[n] * siz[e.to] * vl[n];
      siz[n] += siz[e.to];
    }
    ans += 1ll * siz[n] * (tot[u[n]] - siz[n]) * vl[n];
  };
  FOR(i, sz) if (not vis[i]) f(f, i);
  print(ans << 1);
}
#include "YRS/Z_H/main.hpp"