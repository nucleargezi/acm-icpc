#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

// #define tests
void Yorisou() {
  INT(n, m, s, t);
  --s, --t;
  map<PII, int> mp;
  VEC(T4<int>, e, m);
  int tot = 0;
  vector<vector<int>> city(n);
  for (meion &[x, xx, y, yy] : e) {
    --x, --xx, --y, --yy;
    if (not mp.contains({x, xx})) {
      mp[{x, xx}] = n + tot++;
    }
    city[x].emplace_back(xx);
    if (not mp.contains({y, yy})) {
      mp[{y, yy}] = n + tot++;
    }
    city[y].emplace_back(yy);
  }

  graph<ll, 1> g(n + tot);
  for (int i = 0; i < n; ++i) {
    for (int x : city[i]) {
      int lo = mp[{i, x}];
      g.add(lo, i, 1'000'000'000);
      g.add(i, lo, 0);
    }
  }
  for (meion [x, xx, y, yy] : e) {
    int A = mp[{x, xx}], B = mp[{y, yy}];
    g.add(A, B, 1);
    g.add(B, A, 1);
  }
  g.build();
  ll X = dijkstra(g, s).first[t] - 1'000'000'000;
  UL(X / 1'000'000'000, X % 1'000'000'000);
}
#include "MeIoN_Lib/Z_H/main.hpp"