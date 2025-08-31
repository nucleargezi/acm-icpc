#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bellman_ford.hpp"

#define tests
void Yorisou() {
  INT(n, m);
  graph<ll, 1> g(n);
  while (m--) {
    INT(x, y, w);
    --x, --y;
    g.add(x, y, w);
    if (w >= 0) g.add(y, x, w);
  }
  g.build();
  YES(bellman_ford(g, 0).first.empty());
}
#include "YRS/Z_H/main.hpp"