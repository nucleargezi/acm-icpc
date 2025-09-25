#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"

#define tests
using mono = a_monoid_sum_add<ll>;
int T = 0;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(N);
  VEC(int, a, N);
  Z u = a;
  unique(u);
  for (int &x : a) x = lower_bound(u, x);
  const int sz = len(u);
  graph g(N);
  g.read_tree();
  tree v(g);

  vector<vector<int>> s(sz);
  vector<int> fa(N);
  vector<vector<int>> go(N);
  FOR(i, N) s[a[i]].ep(i);
  FOR(i, sz) {
    sort(all(s[i]), [&](int x, int y) -> bool {
      return v.L[x] < v.L[y];
    });
    int fa = v.LCA(s[i][0], s[i].back());
    go[fa].ep(i);
  }

  lazy_tree_monoid<tree<graph<>>, mono> A(v), B(v);
  vector<int> dp(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    for (Z &&e : g[n]) {
      if (e.to == fa) continue;
      f(f, e.to, n);
      dp[n] += dp[e.to];
    }

    for (int col : go[n]) {
      Z &se = s[col];
      const int sz = len(se);
      int s = 0, sc = 0;
      FOR(i, sz) {
        int x = se[i];
        s += A.prod_path(x, n);
        sc += B.prod_path(x, n);
        if (i > 0) {
          int fa = v.LCA(se[i], se[i - 1]);
          s -= A.prod_path(fa, n);
          sc -= B.prod_path(fa, n);
        }
      }
      chmax(dp[n], sc - s + 1);
    }
    A.apply(n, dp[n]);
    if (fa != -1) B.apply(fa, dp[n]);
  };
  f(f, 0, -1);
  print(dp[0]);
}
#include "YRS/Z_H/main.hpp"