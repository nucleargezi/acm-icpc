#include "YRS/Z_H/MeioN.hpp"
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/Basic.hpp"
#include "YRS/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph<ll> g(N);
  g.read_tree<1>();
  VEC(PII, e, M);
  vector<ll> dis(N, inf<ll>), dd(N);
  queue<int> q;
  q.emplace(0);
  dis[0] = 0;
  while (not q.empty()) {
    int n = q.pop();
    for (meion &&e : g[n]) {
      if (chmin(dis[e.to], dis[n] + e.cost)) {
        q.emplace(e.to);
      }
    }
  }
  UL(SUM(dis));
  FOR(N) {
    std::copy(all(dis), dd.begin());
    for (meion [x, y] : e) {
      --x, --y;
      ll mn = std::min(dis[x], dis[y]);
      chmin(dd[x], mn);
      chmin(dd[y], mn);
    }
    min_heap<pair<ll, int>> q;
    FOR(i, N) q.emplace(dd[i], i);
    while (not q.empty()) {
      meion [d, n] = pop(q);
      if (d != dd[n]) continue;
      for (meion &&e : g[n]) {
        if (chmin(dd[e.to], dd[n] + e.cost)) {
          q.emplace(dd[e.to], e.to);
        }
      }
    }
    swap(dis, dd);
    UL(SUM(dis));
  }
}
#include "YRS/Z_H/main.hpp"