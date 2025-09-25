#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  graph g(N);
  g.read_tree();
  tree v(g);
  vector<int> sz = v.subtree_size_arr();

  vector dp(N, vector<mint>(1));
  for (int n : reversed(v.V)) {
    vector<int> ch = v.collect_child(n);
    dp[n][0] = 1;
    int s = 1;
    for (int to : ch) {
      int t = sz[to];
      vector<mint> ndp(s + t);
      FOR(i, t + 1) FOR(k, s) ndp[i + k] += dp[to][i] * dp[n][k];
      s += t;
      dp[n].swap(ndp);
    }
    dp[n].ep(0);
    vector<mint> ndp(sz[n] + 1);
    FOR(i, sz[n] + 1) {
      if (i == a[n]) ndp[i] = i ? dp[n][i - 1] : 0;
      else ndp[i] = dp[n][i];
    }
    dp[n].swap(ndp);
  }
  print(SUM<mint>(dp[0]));
}
#include "YRS/Z_H/main.hpp"