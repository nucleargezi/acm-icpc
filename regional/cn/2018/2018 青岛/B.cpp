#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/Basic.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/graph/Tree/fast_lca.hpp"

#define tests
void Yorisou() {
  INT(N, M, Q);
  VEC(int, a, M);
  for (int &x : a) --x;
  vector<u8> vis(N);
  for (int x : a) vis[x] = 1;
  graph<ll> g(N);
  g.read_tree<1>();
  tree v(g);
  fast_LCA seg(v);
  vector<int> an(N, -1);
  vector<ll> vl(N);
  for (int x : v.V) {
    if (vis[x]) an[x] = x;
    vl[x] = seg.dist_weighted(x, an[x]);
    for (int t : v.collect_child(x)) {
      an[t] = an[x];
    }
  }

  FOR(Q) {
    INT(sz);
    VEC(int, c, sz);
    for (int &x : c) --x;
    ll r = 0;
    for (int x : c) chmax(r, vl[x]);
    vector<int> go;
    print(binary_search([&](ll lm) -> bool {
      go.clear();
      for (int x : c) if (vl[x] > lm) go.ep(x);
      if (go.empty()) return true;
      int anc = go[0];
      for (int x : go) anc = seg.LCA(anc, x);
      for (int x : go) if (lm < seg.dist_weighted(x, anc)) return false;
      return true;
    }, r, -1));
  }
}
#include "YRS/Z_H/main.hpp"