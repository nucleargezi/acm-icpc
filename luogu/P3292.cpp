#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/ds/monoid/vector_space.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  graph g(N);
  g.read_tree();
  tree v(g);
  tree_monoid_ST<decltype(v), monoid_vector_space<ll>> seg(v, [&](int i) {
    return vector_space<ll>({a[i]}, 0);
  });
  FOR(Q) {
    INT(x, y);
    --x, --y;
    print(seg.prod_path(x, y).get_max());
  }
}
#include "YRS/Z_H/main.hpp"