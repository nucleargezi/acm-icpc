#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/tree_diameter.hpp"

// #define tests
void Yorisou() {
  LL(n);
  graph<ll> g(n);
  g.read_tree<1, 0>();
  meion [seg, path] = tree_diameter(g);
  UL(seg, len(path));
  UL(path);
}
#include "MeIoN_Lib/Z_H/main.hpp"