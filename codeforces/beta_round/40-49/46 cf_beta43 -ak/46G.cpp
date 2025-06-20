#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/jen/special_hull.hpp"

// #define tests
void Yorisou() {
  LL(n);
  YES();
  for (meion [x, y] : hull_with_shortest_edge(n)) {
    UL(x, y);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"