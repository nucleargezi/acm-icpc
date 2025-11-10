#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/graph/Tree/rerooting_tree_dp.hpp"

// #define tests
using mint = M99;
using X = pair<mint, mint>;
void Yorisou() {
  INT(N);
  VEC(mint, a, N);
  graph g(N);
  vector<mint> b(N - 1), c(b);
  FOR(i, N - 1) {
    INT(x, y);
    g.add(x, y);
    IN(b[i], c[i]);
  }
  g.build();
  tree v(g);
  static constexpr X unit = X(0, 0);
  Z fee = [](X x, X y) { return X(x.fi + y.fi, x.se + y.se); };
  Z fev = [&](X x, int i) -> X { return X(x.fi + 1, x.se + a[i]); };
  Z fve = [&](X x, const Z &e) -> X { return X(x.fi, x.se * b[e.id] + x.fi * c[e.id]); };
  rerooting_tree_dp<decltype(v), X> dp(v, fee, fev, fve, unit);
  vector<mint> ans(N);
  FOR(i, N) ans[i] = dp[i].se;
  print(ans);
}
#include "YRS/Z_H/main.hpp"