#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/graph/Tree/tree_abelgroup.hpp"

// #define tests
using mono = monoid_add<ll>;
void Yorisou() {
  INT(N);
  graph g(N);
  int rt = -1;
  FOR(i, N) {
    INT(fa);
    --fa;
    if (fa != -1) g.add(fa, i); 
    else rt = i;
  }
  assert(rt != -1);
  g.build();
  tree v(g, rt);
  tree_abelgroup<decltype(v), mono> seg(
      v, [&](int i) -> ll { return 1ll << 30; });

  vector<T4<int>> quis;
  INT(Q);
  FOR(i, Q) {
    INT(op);
    if (op == 1) {
      INT(x, y, c);
      --x, --y;
      quis.ep(i - c - 1, i, x, y);
    } else {
      INT(x);
      --x;
      quis.ep(i, i, x, -1);
    }
  }
  sort(quis);

  vector<T3<int>> ans;
  for (Z [_, id, x, y] : quis) {
    if (y == -1) {
      seg.multiply(x, 1);
    } else {
      ll s = seg.prod_path(x, y);
      ans.ep(id, s >> 30, s & ((1ll << 30) - 1));
    }
  }
  sort(ans);
  for (Z [id, c, s] : ans) print(c, s);
}
#include "YRS/Z_H/main.hpp"