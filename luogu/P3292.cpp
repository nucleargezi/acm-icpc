#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/graph/Tree/tree_monoid_ST.hpp"
#include "YRS/ds/monoid/vector_space.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  graph<ll> g(N);
  g.read_tree();
  tree v(g);
  tree_monoid_ST<decltype(v), monoid_vector_space<ll>> seg(v, [&](int i) {
    vector_space<ll> s;
    s.add(a[i]);
    return s;
  });
  FOR(Q) {
    INT(x, y);
    --x, --y;
    print(seg.prod_path(x, y).get_max());
  }
}
#include "YRS/Z_H/main.hpp"