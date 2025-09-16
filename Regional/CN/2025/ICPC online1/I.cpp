#include "YRS/Z_H/MeioN.hpp"
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  INT(N, M, V, T);
  --T;
  graph g(N);
  g.read_graph<1>(M);
  vector<PII> dis(N, inf<PII>);
  min_heap<pair<PII, int>> q;
  q.emplace(PII{1, -V}, T);
  dis[T] = {1, -V};
  while (not q.empty()) {
    meion [d, n] = pop(q);
    if (d != dis[n]) continue;
    for (meion &&e : g[n]) if (e.cost <= V) {
      PII nx = dis[n];
      nx.second += e.cost;
      if (nx.second > 0) {
        ++nx.first;
        nx.second = -V + e.cost;
      }
      if (chmin(dis[e.to], nx)) {
        q.emplace(nx, e.to);
      }
    }
  }
  vector<int> ans(N);
  FOR(i, N) {
    if (dis[i].first == inf<int>) ans[i] = -1;
    else ans[i] = dis[i].first;
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"