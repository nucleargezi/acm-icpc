#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/k_shortest/k_shortest_dis_fast.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, s, t, k);
  graph<ll, 1> g(n);
  g.read_graph<1, 0>(m);
  for (ll x : k_shortest_dis_fast<ll>(g, s, t, k)) {
    UL(x == inf<ll> ? -1 : x);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"