#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/ds/monoid/add_pair.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using mint = M99;
struct mono {
  using MX = monoid_add_pair<mint>;
  using MA = monoid_add<int>;
  using X = MX::X;
  using A = MA::X;

  static constexpr X act(X x, A a, ll) {
    x.se += x.fi * a;
    return x;
  }
};
using X = mono::X;
void Yorisou() {
  INT(N, Q, K);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g.add(f, i);
  }
  g.build();
  tree v(g);
  lazy_tree_monoid<decltype(v), mono> seg(v, [&](int i) -> X {
    return X(mint(v.deep[i] + 1).pow(K) - mint(v.deep[i]).pow(K), 0);
  });
  
  vector<T3<int>> quis;
  vector<mint> ans(Q);
  FOR(i, Q) {
    INT(r, z);
    --z;
    --r;
    quis.ep(r, z, i);
  }
  sort(quis);

  int t = 0;
  FOR(i, N) {
    seg.apply_path(0, i, 1);
    while (t < Q and std::get<0>(quis[t]) <= i) {
      Z [r, z, id] = quis[t];
      ans[id] = seg.prod_path(0, z).se;
      ++t;
    }
  }
  for (Z x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"