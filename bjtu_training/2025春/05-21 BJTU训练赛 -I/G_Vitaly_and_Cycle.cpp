#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/ds/rollback/rollback_dsu_bipartite.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
using ddsu = rollback_dsu_bipartite;
void Yorisou() {
  LL(n, m);
  graph g(n);
  ddsu f(n);
  dsu d(n << 1);
  g.read_graph(m);
  for (meion &&e : g.edges) {
    f.merge(e.f, e.to);
    d.merge(e.f << 1, e.to << 1 | 1);
    d.merge(e.to << 1, e.f << 1 | 1);
  }
  meion in = g.deg_array_inout().first;
  if (not m) {
    iroha UL(3, n * (n - 1) * (n - 2) / 6);
  }
  if (f.get_c()) {
    iroha UL(0, 1);
  }
  vector<ll> c(n << 1);
  FOR(i, n) ++c[d[i << 1]];
  ll s = 0;
  FOR(i, n << 1) s += c[i] * (c[i] - 1) >> 1;
  if (s) iroha UL(1, s);
  UL(2, m * (n - 2));
}
#include "MeIoN_Lib/Z_H/main.hpp"