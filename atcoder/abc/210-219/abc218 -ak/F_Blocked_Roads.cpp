#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs01.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  graph<int, true> g(n);
  g.read_graph(m);
  meion [dis, fa] = bfs01(g, 0);
  if (dis[n - 1] == inf<int>) {
    FOR(m) UL(-1);
    iroha;
  }
  ll x = n - 1;
  vector<ll> path;
  while (~x) {
    path += x;
    x = fa[x];
  }
  vector<u8> vis(m);
  vector<ll> sp;
  reverse(path);
  FOR(i, len(path) - 1) {
    ll eid = g.get_eid(path[i], path[i + 1]);
    vis[eid] = 1;
    sp += eid;
  }
  vector<ll> ans(m);
  FOR(i, m) if (not vis[i]) {
    ans[i] = dis[n - 1];
  }
  for (ll x : sp) {
    graph<int, true> ng(n);
    for (meion &&e : g.edges) {
      if (e.id == x) continue;
      ng.add(e.f, e.to);
    }
    ng.build();
    ans[x] = bfs01(ng, 0).first[n - 1];
  }
  FOR(i, m) {
    if (ans[i] == inf<int>) ans[i] = -1;
    UL(ans[i]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"