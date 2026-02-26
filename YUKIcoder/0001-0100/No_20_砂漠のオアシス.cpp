#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/g/dijkstra.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, V, x, y);
  --x, --y;
  retsu<int> a(N, N);
  FOR(y, N) FOR(x, N) IN(a[x][y]);

  graph<int, 1> g(N * N);
  Z id = [&](int x, int y) { return x * N + y; };
  int re = x != -1 ? id(x, y) : -1;
  FOR(i, N) FOR(k, N) {
    if (i) {
      g.add(id(i, k), id(i - 1, k), a[i - 1][k]);
      g.add(id(i - 1, k), id(i, k), a[i][k]);
    }
    if (k) {
      g.add(id(i, k), id(i, k - 1), a[i][k - 1]);
      g.add(id(i, k - 1), id(i, k), a[i][k]);
    }
  }
  g.build();
  int s = id(0, 0), t = id(N - 1, N - 1);
  vc<int> ds = dijkstra(g, s).fi, dt = re != -1 ? dijkstra(g, id(x, y)).fi : vc<int>{};
  YES(ds[t] < V or (re != -1 and ds[re] < V and 2 * (V - ds[re]) > dt[t]));
}
#include "YRS/aa/main.hpp"