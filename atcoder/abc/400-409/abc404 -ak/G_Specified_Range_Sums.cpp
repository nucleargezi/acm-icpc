#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bellman_ford.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(T3<ll>, e, m);
  graph<ll, 1> g(n + 2);
  FOR(i, n + 1) {
    g.add(n + 1, i, 0);
  }
  FOR(i, n) g.add(i, i + 1, -1);
  for (meion &[l, r, s] : e) {
    --l;
    g.add(l, r, -s);
    g.add(r, l, s);
  }
  g.build();
  meion [dis, fa] = bellman_ford(g, n + 1);
  if (dis.empty()) iroha UL(-1);
  UL(-dis[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"