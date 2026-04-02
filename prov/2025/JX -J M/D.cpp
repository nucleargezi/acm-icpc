#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
struct dsu {
  dsu(int _n = 0) : n(_n), fa(_n) { iota(all(fa), 0); }

  int operator[](int x) { return ff(x); }
  
  bool merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) return false;
    if (x > y) swap(x, y);
    fa[y] = x;
    return true;
  }
  
  int n;
  vector<int> fa;

  int ff(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
  }
};
void Yorisou() {
  INT(N, a, b);
  VEC(T3<int>, e, a);
  VEC(T3<int>, r, b);
  vector<int> u;
  for (Z &[x, y, w] : e) --x, --y, u.ep(w);
  for (Z &[x, y, w] : r) --x, --y, u.ep(w);
  unique(u);

  const int sz = len(u);
  vector<vector<PII>> s(sz), t(sz);
  for (Z &[x, y, w] : e) {
    w = lower_bound(u, w);
    s[w].ep(x, y);
  }
  for (Z &[x, y, w] : r) {
    w = lower_bound(u, w);
    t[w].ep(x, y);
  }

  dsu g(N), h(N);
  FOR(i, sz) {
    vector<int> go;
    for (Z [x, y] : s[i]) {
      go.ep(g[x]);
      go.ep(g[y]);
    }
    for (Z [x, y] : t[i]) {
      go.ep(h[x]);
      go.ep(h[y]);
    }
    for (Z [x, y] : s[i]) {
      g.merge(g[x], g[y]);
    }
    for (Z [x, y] : t[i]) {
      h.merge(h[x], h[y]);
    }
    unique(go);
    for (int x : go) {
      if (g[x] != h[x]) return NO();
    }
  }
  YES();
}
#include "YRS/Z_H/main.hpp"