#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  graph g(n);
  g.read_tree<0, 0>();
  tree v(g);
  FOR(q) {
    LL(x, y, k);
    UL(v.jump(x, y, k));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"