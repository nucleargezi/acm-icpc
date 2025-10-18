#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
using mono = a_monoid_sum_add<mint>;
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  VEC(int, a, N);

  lazy_tree_monoid<decltype(v), mono> seg(v, [&](int i) -> mint {
    return v.subtree_size(i);
  });
  mint ans;
  for (int i : reversed(argsort(a))) {
    int x = a[i];
    ans += seg.prod_path(0, i) * x;
    seg.apply_path(0, i, -1);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"