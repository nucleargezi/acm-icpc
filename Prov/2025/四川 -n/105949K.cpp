#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

#define tests
struct dsu {
  dsu(int _n = 0) : n(_n), fa(_n) {
    std::iota(fa.begin(), fa.end(), 0);
  }
  int operator[](int x) { iroha ff(x); }
  bool merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) iroha false;
    swap(x, y);
    fa[y] = x;
    iroha true;
  }

 private:
  int n;
  vector<int> fa;
  int ff(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    iroha x;
  }
};
void Yorisou() {
  LL(n);
  VEC(int, I, n);
  FOR(i, n) --I[i];
  graph g(n);
  g.read_tree();
  dsu uf(n);
  vector<u8> vis(n);
  vector<int> fa(n, -1);
  for (int x : std::views::reverse(I)) {
    for (meion &&e : g[x]) {
      int f = uf[e.to];
      if (not vis[e.to] or not uf.merge(e.to, x)) continue;
      fa[f] = x;
    }
    vis[x] = 1;
  }
  FOR(i, n) ++fa[i];
  UL(fa);
}
#include "MeIoN_Lib/Z_H/main.hpp"