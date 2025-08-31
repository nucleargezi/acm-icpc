#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"
#include "MeIoN_Lib/alg/slope/CHT.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  graph<ll, 1> g(n), rg(n);
  VEC(T4<ll>, e, m);
  for (meion &[x, y, t, w] : e) {
    g.add(--x, --y, t);
    rg.add(y, x, t);
  }
  g.build();
  rg.build();
  meion s = dijkstra(g, 0).first, t = dijkstra(rg, n - 1).first;
  CHT_min<ll> seg;
  for (meion [fir, to, t0, w] : e) {
    if (s[fir] == inf<ll> or t[to] == inf<ll>) continue;
    seg.add(-w, t0 + s[fir] + t[to]);
  }
  LL(q);
  FOR(q) {
    LL(x);
    print("{}", seg.min(x));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"