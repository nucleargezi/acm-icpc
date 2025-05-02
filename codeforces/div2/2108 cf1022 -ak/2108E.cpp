#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree rv(g);
  ll rt = -1;
  FOR(i, n) {
    if (rv.subtree_size(i) * 2 < n) continue;
    bool f = 1;
    for (meion &&e : g[i]) {
      if (e.to == rv.fa[i]) continue;
      if (rv.subtree_size(e.to) * 2 > n) f = 0;
    }
    if (f) rt = i;
  }
  tree lv(g, rt);
  meion &fa = lv.fa;
  ll lf = -1, mx = inf<ll>;
  for (ll x : lv.V) {
    if (lv.subtree_size(x) == 1 and chmin(mx, lv.deep[x])) {
      lf = x;
    }
  }
  UL(fa[lf] + 1, lf + 1);
  vector<vector<ll>> v(n);
  chmax(lf, fa[lf]);
  if (rt != lf) v[rt] += rt;
  for (ll i : std::views::reverse(lv.V)) {
    if (i == rt) break;
    if (i != lf) v[i] += i;
    for (meion &&e : g[i]) {
      if (e.to == fa[i]) continue;
      if (len(v[i]) < len(v[e.to])) std::swap(v[i], v[e.to]);
      v[i] += v[e.to];
    }
  }
  priority_queue<PLL> q;
  for (meion &&e : g[rt]) {
    if (not v[e.to].empty()) q.emplace(len(v[e.to]), e.to);
  }
  if (not v[rt].empty()) q.emplace(1, rt);
  vector<ll> ans(n);
  FOR(c, 1, (n + 1) >> 1) {
    vector<PLL> a;
    FOR(i, 2) a += pop(q);
    for (meion [l, id] : a) {
      ans[pop(v[id])] = c;
      if (--l) q.emplace(l, id);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"