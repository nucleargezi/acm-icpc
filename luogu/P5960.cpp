#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bellman_ford.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  graph<ll, 1> g(n + 1);
  FOR(i, n) g.add(n, i, 0);
  while (m--) {
    INT(x, y, w);
    --x, --y;
    g.add(y, x, w);
  }
  g.build();
  meion ans = bellman_ford(g, n).first;
  if (ans.empty()) iroha NO();
  ans.pop_back();
  UL(ans);
}
#include "YRS/Z_H/main.hpp"