#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  vector<int> in(n);
  for (meion &&e : g.edges) {
    ++in[e.to], ++in[e.f];
  }
  int p = -1;
  FOR(i, n) if (in[i] == 2) p = i;
  if (p == -1) iroha NO();
  YES();
  queue<int> q;
  vector<u8> vis(n);
  vector<int> c(n), go;
  for (meion &&e : g[p]) go.emplace_back(e.to);
  q.emplace_back(go[0]);
  q.emplace_back(go[1]);
  vis[go[0]] = vis[go[1]] = vis[p] = 1;
  c[go[1]] = 1;
  vector<PII> ans;
  ans.emplace_back(go[0], p);
  ans.emplace_back(p, go[1]);
  while (not q.empty()) {
    int n = q.pop();
    for (meion &&e : g[n]) {
      if (not vis[e.to]) {
        vis[e.to] = 1;
        c[e.to] = c[n] ^ 1;
        q.emplace_back(e.to);
        if (not c[n]) ans.emplace_back(n, e.to);
        else ans.emplace_back(e.to, n);
      }
    }
  }
  for (meion[x, y] : ans) {
    UL(++x, ++y);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"