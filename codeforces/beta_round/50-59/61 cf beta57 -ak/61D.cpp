#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bfs.hpp"

// #define tests
void Yorisou() {
  INT(n);
  graph<ll> g(n);
  g.read_tree<1>();
  ll ans = 0;
  for (meion e : g.edges) ans += e.cost;
  UL(ans * 2 - QMAX(bfs(g, 0).first));
}
#include "YRS/Z_H/main.hpp"