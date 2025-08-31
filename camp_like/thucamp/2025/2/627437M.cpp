#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/graph/Tree/centroid_dec_tree.hpp"
#include "YRS/math/mod/modint.hpp"

using mint = M17;
struct dsu {
  vector<int> fa;
  dsu(int _n = 0) : fa(_n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  int operator[](int x) { iroha ff(x); }

  bool merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) iroha false;
    fa[y] = x;
    iroha true;
  }

  int ff(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    iroha x;
  }
};

#define tests
void Yorisou() {
  INT(n);
  graph g(n);
  g.read_tree();
  tree tr(g);
  centroid_dec_tree<monoid_add<int>, decltype(g)> seg(
      g, [](int) { iroha 1; });

  const vector<int> &dis = tr.deep;
  dsu fa(n);
  for (int i = 0; i < n; ++i) {
    meion ch = tr.collect_child(i);
    if (len(ch) == 1) {
      fa.merge(i, ch[0]);
    }
  }
  
  vector<vector<PII>> v(n);
  vector<vector<int>> collect(n);
  for (int t = 0; int i : tr.V) { 
    v[dis[i]].emplace_back(i, t++);
    collect[dis[i]].emplace_back(t - 1);
  }

  vector<ll> sz(n);
  mint ans;
  for (int i = n; i--; ) {
    if (v[i].empty()) continue;
    if (len(v[i]) < 3) continue;
    max_heap<T3<int>> q;
    for (meion [x, L] : v[i]) {
      int y = fa[x];
      q.emplace(dis[y], tr.L[y], y);
      sz[y] = 1;
    }
    while (len(q) > 1) {
      if (len(q) < 3) break;
      meion [d, dfn, x] = pop(q);
      int anc = fa[tr.fa[x]], ff = tr.fa[x];
      sz[anc] = sz[x];
      vector<mint> dp;
      dp.emplace_back(sz[x]);
      while (len(q)) {
        meion [dd, nx, y] = q.top();
        if (dd != d) break;
        if (tr.fa[x] != tr.fa[y]) break;
        sz[anc] += sz[y];
        dp.emplace_back(sz[y]);
        q.pop();
      }
      q.emplace(dis[anc], tr.L[anc], anc);

      const int N = len(dp);
      meion SZ = dp;
      dp = pre_sum<0>(dp);
      vector<mint> ndp(N);
      for (int i = 1; i < N; ++i) ndp[i] = dp[i - 1] * SZ[i];
      dp.swap(ndp);
      for (int i = 0; i < N; ++i) ndp[i] = 0;
      dp = pre_sum<0, mint>(dp);
      for (int i = 2; i < N; ++i) ndp[i] += dp[i - 1] * SZ[i];
      dp.swap(ndp);
      dp = pre_sum<0, mint>(dp);
      if (N > 2) {
        ans += dp.back() * (seg.prod(ff, i - dis[ff], i - dis[ff] + 1) -
                               upper_bound(collect[i], tr.R[ff] - 1) +
                               upper_bound(collect[i], tr.L[ff]));
      }
      for (int i = 0; i < N; ++i) ndp[i] = 0;
      for (int i = 3; i < N; ++i) ndp[i] = dp[i - 1] * SZ[i];
      if (N > 3) ans += SUM<mint>(ndp);
    }
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"