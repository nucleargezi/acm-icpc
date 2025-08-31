#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/scc.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  VEC(int, esz, n);
  graph<int, 1> g(n);
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < esz[i]; ++k) {
      INT(t);
      --t;
      g.add(i, t);
    }
  }
  g.build();

  auto [N, id] = scc_id(g);
  auto v = scc_dag(g, N, id);
  vector<u8> vis(N);
  vector<int> sz(N);
  for (int i = 0; i < n; ++i) ++sz[id[i]];
  vector<int> c(N);
  for (int i = 0; i < n; ++i) {
    c[id[i]] += a[i];
  }
  for (int i = 0; i < N; ++i) {
    vis[i] |= not not c[i];
  }

  vector<int> in = v.deg_array_inout().first;
  queue<int> q;
  for (int i = 0; i < N; ++i) if (not in[i]) q.emplace_back(i);
  vector<u8> cov(N);
  while (not q.empty()) {
    int fir = q.front();
    q.pop();
    if (vis[fir] and sz[fir] > 1) {
      cov[fir] = 1;
    }
    for (auto &&e : v[fir]) {
      vis[e.to] |= vis[fir];
      cov[e.to] |= cov[fir];
      if (not --in[e.to]) {
        q.emplace_back(e.to);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (cov[i]) ans += sz[i];
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"