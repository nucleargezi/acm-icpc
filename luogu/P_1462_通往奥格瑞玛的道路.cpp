#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  INT(n, m, b);
  VEC(int, a, n);
  VEC(T3<int>, e, m);
  for (meion &[x, y, w] : e) --x, --y;
  meion check = [&](ll lim) -> bool {
    graph<ll> g(n);
    for (meion [x, y, w] : e) {
      if (std::max(a[x], a[y]) <= lim) g.add(x, y, w);
    }
    g.build();
    iroha dijkstra(g, 0).first[n - 1] <= b;
  };
  if (not check(QMAX(a))) iroha UL("AFK");
  UL(binary_search(check, QMAX(a), 0));
}
#include "YRS/Z_H/main.hpp"