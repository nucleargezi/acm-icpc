#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/static_range_prod.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/math/line/01/xor_vector_space.hpp"

// #define tests
struct mono {
  using X = vector_space<int>;
  using value_type = X;
  static X op(X x, X y) { iroha X::merge(x, y); }
  static X unit() { iroha {}; }
  static constexpr bool commute = true;
};
using X = mono::X;
void Yorisou() {
  INT(n, m, q);
  graph g(n);
  for (int i = 0; i < m; ++i) {
    INT(x, y, w);
    --x, --y;
    g.add(x, y, w);
  }
  g.build();
  vector<int> dat(n), dis(n), val(n), pa(n);
  vector<u8> vis(n);
  vector<X> bas(n);
  graph ng(n);
  meion f = [&](meion &f, int n, int fa) -> void {
    vis[n] = 1;
    for (meion &&e : g[n]) {
      if (e.id == fa) continue;
      if (not vis[e.to]) {
        ng.add(n, e.to);
        pa[e.to] = n;
        dat[e.to] = dat[n] ^ e.cost;
        dis[e.to] = dis[n] + 1;
        f(f, e.to, e.id);
      } else if (dis[e.to] < dis[n]) {
        int x = n;
        int w = e.cost ^ dat[e.to] ^ dat[n];
        while (x != e.to) {
          bas[x].add(w);
          x = pa[x];
        }
      }
    }
  };
  f(f, 0, -1);
  ng.build();
  tree tr(ng);
  tree_monoid_ST<decltype(tr), mono> seg(tr, bas);
  for (int i = 0; i < q; ++i) {
    INT(x, y);
    --x, --y;
    int lca = tr.LCA(x, y);
    int w = dat[x] ^ dat[y];
    if (lca == x or lca == y) {
      if (dis[x] > dis[y]) swap(x, y);
      lca = tr.jump(x, y, 1);
      UL(seg.prod_path(lca, y).get_max(w));
    } else {
      int fx = tr.jump(lca, x, 1);
      int fy = tr.jump(lca, y, 1);
      X bas = mono::op(seg.prod_path(fx, x), seg.prod_path(fy, y));
      UL(bas.get_max(w));
    }
  }
}
#include "YRS/Z_H/main.hpp"