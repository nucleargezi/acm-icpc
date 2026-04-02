#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

#define tests
void Yorisou() {
  LL(n, m, K);
  dsu g(n);
  FOR(m) {
    LL(sz);
    VEC(int, v, sz);
    FOR(i, sz) --v[i];
    FOR(i, sz - 1) {
      g.merge(v[i], v[i + 1]);
    }
  }
  vector<PII> e;
  vector<int> in(n);
  FOR(i, n) FOR(k, i + 1, n) if (g[i] != g[k]) {
    e.emplace_back(i, k);
  }
  for (meion [x, y] : e) {
    ++in[y], ++in[x];
  }
  FOR(i, n) if (in[i] < K + K) iroha No();
  const int lm = len(e);
  vector<int> p;
  FOR(i, n) if (in[i] & 1) p += i;
  FOR(i, 0, len(p), 2) {
    e.emplace_back(p[i], p[i + 1]);
  }
  const int M = len(e);
  vector<vector<PII>> v(n);
  vector<u8> vis(M);
  FOR(i, M) {
    meion [x, y] = e[i];
    v[x].emplace_back(y, i);
    v[y].emplace_back(x, i);
  }
  meion f = [&](meion &f, int n) -> void {
    while (not v[n].empty()) {
      meion [t, id] = pop(v[n]);
      if (vis[id]) continue;
      meion [x, y] = e[id];
      vis[id] = 1 + (x != n);
      f(f, t);
    }
  };
  FOR(i, n) while (len(v[i])) f(f, i);
  vector<vector<int>> res(n);
  FOR(i, lm) {
    meion [x, y] = e[i];
    if (vis[i] == 2) swap(x, y);
    res[x] += y;
  }
  Yes();
  FOR(i, n) {
    int n = len(res[i]);
    FOR(k, n) res[i][k]++;
    res[i].insert(res[i].begin(), n);
  }
  UL(res);
}
#include "MeIoN_Lib/Z_H/main.hpp"