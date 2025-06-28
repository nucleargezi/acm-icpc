#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
struct dsu {
  vector<int> fa;
  dsu(int n) : fa(n) { FOR(i, n) fa[i] = i; }
  int ff(int x) { iroha fa[x] == x ? x : fa[x] = ff(fa[x]); }
  void merge(int x, int y) { fa[y] = x; }
};
void Yorisou() {
  LL(n, m);
  VEC(PLL, e, m);
  vector<set<int>> v(n);
  for (meion &[ x, y ] : e) {
    --x, --y;
    v[x] += y, v[y] += x;
  }
  dsu g(n);
  ll ans = m;
  LL(q);
  FOR(q) {
    LL(eid);
    meion [x, y] = e[--eid];
    int fx = g.ff(x), fy = g.ff(y);
    if (fx == fy or not v[fx].contains(fy)) {
      UL(ans);
      continue;
    }
    if (len(v[fx]) < len(v[fy])) swap(fx, fy);
    v[fx].extract(fy), v[fy].extract(fx);
    --ans;
    for (int t : v[fy]) {
      if (t == fx) continue;
      if (v[fx].contains(t)) {
        --ans;
      } else {
        v[fx].emplace(t);
        v[t].emplace(fx);
      }
      v[t].extract(fy);
    }
    v[fy].clear();
    g.merge(fx, fy);
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"