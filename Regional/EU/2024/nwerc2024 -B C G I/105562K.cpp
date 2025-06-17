#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, m, K);
  graph g(n);
  g.read_graph<1>(m);
  vector<pair<ll, RE>> sh(K);
  IN(sh);
  meion s = dijkstra(g, 0).first;
  meion t = dijkstra(g, n - 1).first;
  bool f = 0;
  for (meion [x, p] : sh) f |= p == 1;
  if (not f) iroha impossible();
  for (meion &[x, p] : sh) --x, x = s[x] + t[x];
  sort(sh);
  RE ep = 1, ans = 0;
  for (meion &[x, p] : sh) {
    ans += x * p * ep;
    ep *= (1 - p);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"