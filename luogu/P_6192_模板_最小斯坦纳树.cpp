#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/steiner.hpp"

// #define tests
void Yorisou() {
  LL(n, m, k);
  graph g(n);
  g.read_graph<1>(m);
  VEC(int, a, k);
  FOR(i, k) --a[i];
  meion [ans, vs, es] = steiner_tree<ll>(g, a);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"