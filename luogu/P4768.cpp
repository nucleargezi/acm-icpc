#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/g/dijkstra.hpp"
#include "YRS/tr/doubling.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T4<int>, es, M);
  for (Z &[x, y, w, h] : es) {
    --x, --y;
    h = -h;
    swap(x, h);
    swap(y, w);
  }
  sort(es);
  graph<int> g(N);
  for (Z &[h, w, x, y] : es) {
    g.add(x, y, w);
  }
  g.build();
  vc<int> dis = dijkstra(g, 0).fi;
  sh(dis, N + N - 1);

  int t = N;
  dsu f(N + N - 1);
  vc<int> hi(N + N - 1, inf<int>);
  graph<int> ng(N + N - 1);
  for (Z &[h, w, x, y] : es) {
    x = f[x], y = f[y];
    if (x != y) {
      dis[t] = min(dis[x], dis[y]);
      ng.add(t, x);
      ng.add(t, y);
      f.set(t, x);
      f.set(t, y);
      hi[t] = -h;
      ++t;
    }
  }
  ng.build();
  doubling db(ng, N + N - 2);

  INT(Q, K, S);
  int ans = 0;
  FOR(Q) {
    INT(x, h);
    x = (x + 1ll * K * ans - 1) % N;
    h = (h + 1ll * K * ans) % (S + 1);
    FOR_R(i, db.n) {
      int f = db.fa[i][x];
      if (hi[f] > h) x = f;
    }
    print(ans = dis[x]);
  }
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"