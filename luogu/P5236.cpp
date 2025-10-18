#include "YRS/all.hpp"
#include "YRS/graph/Apck/cactus.hpp"

// #define tests
void Yorisou() {
  INT(n, m, q);
  graph<ll> g(n);
  g.read_graph<1>(m);
  cactus seg(g);
  while (q--) {
    INT(x, y);
    --x, --y;
    UL(seg.dist(x, y));
  }
}
#include "YRS/Z_H/main.hpp"