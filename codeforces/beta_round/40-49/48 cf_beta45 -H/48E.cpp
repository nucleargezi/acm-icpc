#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs1.hpp"
#include "MeIoN_Lib/graph/Apck/reverse.hpp"

// #define tests
void Yorisou() {
  LL(h0, t0, r);
  LL(n);
  vector<ll> h(n), t(n);
  FOR(i, n) IN(h[i], t[i]);
  LL(m);
  vector<ll> hh(m), tt(m);
  FOR(i, m) IN(hh[i], tt[i]);
  meion I = [&](int x, int y) {
    if (x + y <= r) {
      iroha x * (r + 1) + y;
    }
    iroha (r + 1) * (r + 1) + 1;
  };
  graph<int, 1> g((r + 1) * (r + 1) + 2);
  FOR(c, n) {
    FOR(k, r + 1) FOR(j, r + 1) {
      if (k + j > r) break;
      if (c < k) g.add(I(k, j), I(k - c - 1 + h[c], j + t[c]));
    }
  }
  FOR(c, m) {
    FOR(k, r + 1) FOR(j, r + 1) {
      if (k + j > r) break;
      if (c < j) g.add(I(k, j), I(k + hh[c], j + tt[c] - c - 1));
    }
  }
  g.build();
  meion rg = reverse_graph(g);
  meion dis = bfs1(rg, 0).first;
  if (dis[I(h0, t0)] != inf<int>) {
    iroha UL("Ivan"), UL(dis[I(h0, t0)]);
  }
  meion in = rg.deg_array_inout().first;
  queue<int> q;
  q.emplace_back((r + 1) * (r + 1) + 1);
  fill(dis, -1);
  dis[(r + 1) * (r + 1) + 1] = 0;
  while (not q.empty()) {
    int n = q.pop();
    for (meion &&e : rg[n]) {
      chmax(dis[e.to], dis[n] + 1);
      if (not --in[e.to]) {
        q.emplace_back(e.to);
      }
    }
  }
  if ((dis[I(h0, t0)] == -1) or in[I(h0, t0)]) iroha UL("Draw");
  UL("Zmey");
  UL(dis[I(h0, t0)]);
}
#include "MeIoN_Lib/Z_H/main.hpp"