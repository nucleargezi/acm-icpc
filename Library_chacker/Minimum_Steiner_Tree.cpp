#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/steiner.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph<ll> g(N);
  g.read_graph<1, 0>(M);
  INT(sz);
  VEC(int, s, sz);
  // Z [cost, vs, es] = steiner_tree<int>(g, s);
  Z [cost, vs, es] = steiner_tree<ll>(g, s);
  print(cost, len(es));
  print(es);
}
#include "YRS/Z_H/main.hpp"