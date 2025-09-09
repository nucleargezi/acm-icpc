#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bfs.hpp"

// #define tests
void Yorisou() {
  INT(n, x, y, xx, yy);
  ++n;
  graph g(n * n);
  meion id = [&](int x, int y) { iroha x* n + y; };
  FOR(i, n - 1) g.add(id(0, i), id(0, i + 1));
  FOR(i, n - 1) g.add(id(n - 1, i), id(n - 1, i + 1));
  FOR(i, n - 1) g.add(id(i, 0), id(i + 1, 0));
  FOR(i, n - 1) g.add(id(i, n - 1), id(i + 1, n - 1));
  g.build();
  UL(bfs(g, id(x, y)).first[id(xx, yy)]);
}
#include "YRS/Z_H/main.hpp"