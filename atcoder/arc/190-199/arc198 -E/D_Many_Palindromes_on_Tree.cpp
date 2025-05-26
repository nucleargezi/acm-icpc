#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  VEC(string, vis, n);
  FOR(i, n) FOR(k, n) vis[i][k] -= '0';
  dsu f(n);
  vector<vector<PII>> go(n);
  FOR(i, n) FOR(k, i + 1, n) if (vis[i][k]) {
    f.merge(i, k);
    if (v.dist(i, k) >= 2) {
      go[v.dist(i, k)].emplace_back(i, k);
    }
  }
  FOR_R(i, 2, n) {
    for (unique(go[i]); meion [x, y] : go[i]) {
      int d = v.dist(x, y);
      std::tie(x, y) = PII(v.jump(x, y, 1), v.jump(y, x, 1));
      if (x > y) std::swap(x, y);
      f.merge(x, y);
      vis[x][y] = vis[y][x] = 1;
      go[i - 2] += PII(x, y);
    }
  }
  vector<vector<PII>> seg(n);
  int ans = n;
  FOR(i, n) FOR(k, i + 1, n) {
    int d = v.dist(i, k);
    if (d < 3) {
      if (f[i] == f[k]) {
        ans += 2;
        vis[i][k] = vis[k][i] = 1;
      }
    } else {
      seg[d].emplace_back(i, k);
    }
  }
  FOR(i, 3, n) {
    for (meion [x, y] : seg[i]) if (f[x] == f[y]) {
      meion [px, py] = PII(v.jump(x, y, 1), v.jump(y, x, 1));
      vis[y][x] = vis[x][y] = vis[px][py];
      ans += vis[x][y] * 2;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"