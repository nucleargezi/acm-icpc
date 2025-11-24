#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/ds/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree<1>();
  tree v(g);
  Z e = g.edges;
  for (Z &e : e) if (v.deep[e.f] < v.deep[e.to]) swap(e.f, e.to);
  sort(e, [&](edge<int> &a, edge<int> &b) -> bool {
    return a.cost != b.cost ? a.cost < b.cost : v.deep[a.f] > v.deep[b.f];
  });
  dsu f(N);
  vector<ll> ans(N - 1), sz(N);
  for (int l = 0, r; l < N - 1; l = r) {
    r = l;
    while (r < N - 1 and e[r].cost == e[l].cost) ++r;
    FOR(i, l, r) {
      Z [fi, to, w, id] = e[i];
      sz[id] = f.size(fi);
      f.merge(fi, to);
    }
    FOR(i, l, r) {
      Z [fi, to, w, id] = e[i];
      ans[id] = 2 * sz[id] * (f.size(fi) - sz[id]);
    }
  }
  ll mx = QMAX(ans);
  vector<int> r;
  FOR(i, N) if (ans[i] == mx) r.ep(i + 1);
  print(mx, len(r));
  print(r);
}
#include "YRS/Z_H/main.hpp"