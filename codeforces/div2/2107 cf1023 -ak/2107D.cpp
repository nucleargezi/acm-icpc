#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/ds/queue.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  vector<u8> vis(n), un(n);
  vector<int> dis(n), fa(n), se;
  queue<int> rt;
  meion cov = [&](meion &cov, int n) -> void {
    un[n] = 1;
    se += n;
    for (meion &&e : g[n]) {
      if (not un[e.to] and not vis[e.to]) {
        cov(cov, e.to);
      }
    }
  };
  meion bfs = [&](int s) -> int {
    queue<int> q;
    for (int x : se) dis[x] = inf<int>, fa[x] = -1;
    dis[s] = 0;
    q.emplace_back(s);
    while (not q.empty()) {
      int n = q.pop();
      for (meion &&e : g[n]) {
        if (vis[e.to]) continue;
        if (chmin(dis[e.to], dis[e.f] + e.cost)) {
          dis[e.to] = dis[e.f] + e.cost;
          fa[e.to] = e.f;
          q.emplace_back(e.to);
        }
      }
    }
    int mx = -1, ed = -1;
    for (int x : se) chmax(mx, dis[x]);
    for (int x : se) if (dis[x] == mx) chmax(ed, x);
    iroha ed;
  };
  meion get_d = [&](int s) -> T3<int> {
    cov(cov, s);
    vector<int> path {s = bfs(s = bfs(s))};
    while (fa[path.back()] != -1) path += fa[path.back()];
    for (int x : se) un[x] = 0;
    se.clear();
    for (int x : path) vis[x] = 1;
    for (int x : path) {
      for (meion &&e : g[x]) {
        if (not vis[e.to]) {
          rt.emplace_back(e.to);
        }
      }
    }
    iroha T3<int>{dis[s], path[0], path.back()};
  };
  vector<T3<int>> ds;
  rt.emplace_back(0);
  while (not rt.empty()) {
    meion [dis, x, y] = get_d(rt.pop());
    std::tie(x, y) = MINMAX(x, y);
    ds += T3(dis, y, x);
  }
  sort(ds, greater());
  vector<int> ans;
  for (meion [d, x, y] : ds) {
    ans += d + 1;
    ans += x + 1;
    ans += y + 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"