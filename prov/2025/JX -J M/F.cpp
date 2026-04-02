#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M, K);
  vector<vector<int>> v(M);
  vector<vector<int>> s(N);
  FOR(i, M) {
    INT(sz);
    v[i].resize(sz);
    IN(v[i]);
    for (int &x : v[i]) {
      --x;
      s[x].ep(i);
    }
    sort(v[i]);
  }
  FOR(i, N) sort(s[i]);
  vector<int> c(N);
  vector<u8> vis(N);
  vector<T3<int>> es;
  FOR(i, N) {
    vector<int> p, al;
    for (int id : s[i]) {
      for (int t : v[id]) {
        ++c[t];
        if (not vis[t]) al.ep(t);
        vis[t] = 1;
      }
    }
    for (int t : al) es.ep(c[t], i, t);
    for (int t : al) c[t] = 0;
    for (int t : al) vis[t] = 0;
  }
  sort(es, greater());
  dsu g(N);
  set<ll> se;
  for (Z [w, x, y] : es) {
    if (g.merge(x, y)) {
      if (x > y) swap(x, y);
      se.eb(ll(x) << 30 | y);
    }
  }
  FOR(i, M) {
    int n = len(v[i]), c = 0;
    FOR(j, n) FOR(k, j + 1, n) {
      int x = v[i][j], y = v[i][k];
      if (x > y) swap(x, y);
      c += se.contains(ll(x) << 30 | y);
    }
    if (c != n - 1) return NO();
  }
  YES();
}
#include "YRS/Z_H/main.hpp"