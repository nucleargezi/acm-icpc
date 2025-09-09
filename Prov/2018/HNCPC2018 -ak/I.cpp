#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"
#include "YRS/graph/Apck/steiner.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void yorisou(int n, int m) {
  graph g(n);
  g.read_graph<1>(m);
  Z e = g.edges;
  sort(e, [&](edge<int> x, edge<int> y) { return x.cost < y.cost; });
  Z mst = [&](int msk, int sz) -> int {
    dsu g(n);
    int res = 0;
    for (Z [f, t, w, id] : e) {
      if ((msk >> f & 1) and (msk >> t & 1)) {
        if (g.merge(f, t)) res += w;
      }
    }
    int fa = g[0];
    for (int i = 1; i < sz; ++i) if (g[i] != fa) return inf<int>;
    return res;
  };
  FOR(sz, 2, n + 1) {
    if (sz < 14) {
      vector<int> ps(sz);
      FOR(i, sz) ps[i] = i;
      Z [ans, vs, es] = steiner_tree<int>(g, ps);
      UL(ans);
    } else {
      int ans = inf<int>;
      const int N = 1 << (n - sz);
      for (int msk = 0; msk < N; ++msk) {
        chmin(ans, mst((msk << sz) | ((1 << sz) - 1), sz));
      }
      UL(ans);
    }
  }
}
void Yorisou() {
  int n, m;
  while (IN(n, m)) yorisou(n, m);
}
#include "YRS/Z_H/main.hpp"