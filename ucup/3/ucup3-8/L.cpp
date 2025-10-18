#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  vector<vector<int>> v(N), vv;
  vector<int> in(N), ou(N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    v[x].ep(y);
    ++ou[x], ++in[y];
  }
  vv = v;
  
  vector<int> fa(N);
  Z f = [&](Z &f, int n) -> void {
    for (int t : v[n]) {
      if (fa[t] != -1) continue;
      fa[t] = n;
      f(f, t);
    }
  };
  vector<vector<int>> path;
  set<int> se;
  FOR(i, N) if (in[i] > ou[i]) se.eb(i);
  FOR(i, N) while (ou[i] > in[i]) {
    fill(all(fa), -1);
    f(f, i);
    vector<int> go;
    int del = -1;
    for (int t : se) {
      if (fa[t] != -1) {
        int x = t;
        while (x != -1) {
          go.ep(x);
          if (fa[x] != -1) v[fa[x]].erase(std::find(all(v[fa[x]]), x));
          x = fa[x];
        }
        --in[t];
        if (in[t] == ou[t]) del = t;
        break;
      }
    }
    --ou[i];
    path.ep(go);
    if (del != -1) se.extract(del);
  }
  v = vv;

  vector<int> c(N), ans(N);
  vector<char> vis(N);
  for (Z &s : path) {
    fill(all(c), 0);
    const int sz = len(s);
    for (int x : s) if (not vis[x]) c[x] = 1;
    FOR(i, 1, sz) {
      int x = s[i - 1], y = s[i];
      c[y] += c[x];
    }
    for (int x : s) if (vis[x]) c[x] = 0;
    FOR_R(i, N) for (int t : v[i]) chmax(c[i], c[t]);
    FOR(i, N) ans[i] += c[i];
    for (int x : s) vis[x] = 1;
  }
  for (int &x : ans) chmax(x, 1);
  print(ans);
}
#include "YRS/Z_H/main.hpp"