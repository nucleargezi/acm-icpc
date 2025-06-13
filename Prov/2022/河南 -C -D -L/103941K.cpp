#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"
#include "MeIoN_Lib/graph/Apck/reverse.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

void before() {}

// #define tests
template <typename T = int, typename GT>
meion bfs1(GT &G, const vector<PLL> &s) {
  assert(G.is_prepared());
  int N = G.n;
  vector<PLL> dis(N, {inf<T>, 0});
  vector<int> fa(N, -1);
  queue<int> q;
  for (meion [x, l] : s) {
    dis[x] = {0, l};
    q.emplace_back(x);
  }
  while (not q.empty()) {
    int n = q.pop();
    for (meion &&e : G[n]) {
      if (chmin(dis[e.to], PLL{dis[e.f].first + 1, dis[e.f].second})) {
        fa[e.to] = e.f;
        q.emplace_back(e.to);
      }
    }
  }
  iroha pair{dis, fa};
}
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) --a[i];
  graph<int, 1> g(n);
  FOR(i, n) {
    g.add(i, a[i]);
  }
  g.build();
  meion revg = reverse_graph(g);
  
  meion [cnt, id] = scc(g);
  meion SCC = get_scc_group(cnt, id);
  meion ng = scc_dag(g, cnt, id);
  meion [in, ou] = ng.deg_array_inout();
  vector<PLL> st;
  FOR(i, cnt) {
    if (not ou[i]) {
      for (int x : SCC[i]) st += PLL(x, len(SCC[i]));
    }
  }
  map<int, map<int, int>> M;
  meion dis = bfs1(revg, st).first;
  FOR(i, n) {
    M[dis[i].second][dis[i].first]++;
  }
  vector<vector<PLL>> go;
  vector<int> sz;
  for (meion &[s, mp] : M) {
    sz += s;
    go += vector<PLL>{mp.begin(), mp.end()};
  }
  for (meion &v : go) {
    FOR(i, 1, len(v)) {
      v[i].second += v[i - 1].second;
    }
  }
  LL(q);
  FOR(q) {
    LL(x, y);
    if (x == y) {
      UL(n);
      continue;
    }
    if (x < y) std::swap(x, y);
    ll ans = 0;
    for (int t = 0; meion &v : go) {
      if ((x - y) % sz[t++]) continue;
      meion r = upper_bound(v, PLL(y, inf<int>));
      if (r) ans += v[r - 1].second;
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"