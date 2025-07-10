#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  FOR(i, n) --a[i];

  vector<T3<int>> ans;
  vector<vector<int>> v(n);
  FOR(i, n) v[a[i]].emplace_back(i);
  vector<int> vis(n);
  vector<vector<int>> cyc;
  vector<int> path;
  FOR(i, n) if (not vis[i]) {
    int s = i;
    path.clear();
    while (not vis[s]) {
      vis[s] = 1;
      path.emplace_back(s);
      s = a[s];
    }
    if (vis[s] == 1) {
      cyc.emplace_back();
      meion &c = cyc.back();
      for (int x : std::views::reverse(path)) {
        c.emplace_back(x);
        if (x == s) break;
      }
      reverse(c);
    }
    for (int x : path) vis[x] = 2;
  }
  for (meion &c : cyc) {
    FOR(i, 1, len(c)) {
      ans.emplace_back(1, c[0], c[i]);
    }
  }
  
  fill(vis, 0);
  queue<int> q;
  for (meion &c : cyc) {
    for (int x : c) {
      vis[x] = 1;
      q.emplace_back(x);
    }
  }
  while (not q.empty()) {
    int n = q.pop();
    for (int t : v[n]) {
      if (not vis[t]) {
        vis[t] = 1;
        q.emplace_back(t);
        ans.emplace_back(2, n, t);
      }
    }
  }

  print("{}", len(ans));
  for (meion [op, x, y] : ans) {
    print("{} {} {}", op, x + 1, y + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"