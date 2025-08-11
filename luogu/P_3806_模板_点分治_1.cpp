#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  graph<ll> g(n);
  g.read_tree<1>();

  VEC(int, quis, q);
  vector<u8> ans(q);
  
  int mx = QMAX(quis) + 1;
  vector<int> vis(mx);
  int tot = 0;
  centroid_dec seg(g);
  meion f = [&](int n) -> void {
    vector<ll> take;
    meion get_sub = [&](meion &get_sub, int n, int fa, ll dis) -> void {
      take.emplace_back(dis);
      for (meion &&e : g[n]) {
        if (e.to != fa and not seg.dead[e.to] and e.cost + dis < mx) {
          get_sub(get_sub, e.to, n, e.cost + dis);
        }
      }
    };
    vis[0] = ++tot;
    for (meion &&e : g[n]) {
      if (not seg.dead[e.to]) {
        take.clear();
        if (e.cost < mx) get_sub(get_sub, e.to, n, e.cost);
        for (int d : take) {
          for (int i = 0; i < q; ++i)
            if (not ans[i]) {
              int k = quis[i];
              if (k >= d and vis[k - d] == tot) ans[i] = 1;
            }
        }
        for (int d : take)
          if (d < mx) vis[d] = tot;
      }
    }
  };
  seg.keis(0, f);
  for (int i = 0; i < q; ++i) {
    UL(ans[i] ? "AYE" : "NAY");
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"