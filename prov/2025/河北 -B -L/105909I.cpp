#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/graph/Apck/find_centroids.hpp"

#define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  meion c = find_centroids(g);
  if (c.second == -1) UL(1), UL(c.first + 1);
  else UL(2), UL(c.first + 1, c.second + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"