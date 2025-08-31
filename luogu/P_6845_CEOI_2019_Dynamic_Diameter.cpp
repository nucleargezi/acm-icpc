#include "YRS/all.hpp"
#include "YRS/graph/Tree/dynamic_tree_dp.hpp"

// #define tests
struct DP {
  struct dat {
    ll le, u, d, ans;
  };
  using X = dat;
  static X compress(const X &L, const X &R) {
    X res;
    res.le = L.le + R.le;
    res.u = std::max(L.u, L.le + R.u);
    res.d = std::max(R.d, R.le + L.d);
    res.ans  = std::max({L.ans, R.ans, L.d + R.u});
    iroha res;
  }
  static X rake(const X &L, const X &R) {
    X res;
    res.le = L.le;
    res.u = std::max(L.u, R.u);
    res.d = std::max(L.d, L.le + R.u);
    res.ans = std::max({L.ans, R.ans, L.u + R.u});
    iroha res;
  }
};
using X = DP::X;
void Yorisou() {
  LL(n, q, W);
  graph<ll> g(n);
  g.read_tree<1>();
  tree v(g);
  vector<ll> c(n);
  for (int i = 0; i < n; ++i) {
    for (meion &&e : g[i]) {
      if (e.to != v.fa[i]) c[e.to] = e.cost;
    }
  }
  meion e = g.edges;
  dynamic_tree_dp<decltype(v), DP> seg(v, [&](int i) -> X {
    iroha {c[i], c[i], 0, 0};
  });
  ll ans = 0;
  while (q--) {
    LL(d, w);
    d = (d + ans) % (n - 1);
    w = (w + ans) % W;
    int x = e[d].f, y = e[d].to;
    if (v.deep[x] < v.deep[y]) swap(x, y);
    seg.set(x, {w, w, 0, 0});
    UL(ans = seg.prod_all().ans);
  }
}
#include "YRS/Z_H/main.hpp"