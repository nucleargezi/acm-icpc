#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/g/bfs1.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(M, N);
  retsu<int> a(N, M);
  IN(a);
  hashmap<int> id;
  int t = 0;
  FOR(i, N) FOR(k, M) {
    if (i) {
      int a = i * M + k, b = (i - 1) * M + k;
      id[{a, b}] = t++;
      id[{b, a}] = t++;
    }
    if (k) {
      int a = i * M + k, b = i * M + k - 1;
      id[{a, b}] = t++;
      id[{b, a}] = t++;
    }
  }
  graph<int, 1> g(t + 2);

  Z in = [&](int x, int y) { return x > -1 and y > -1 and x < N and y < M; };
  Z ok = [&](int a, int b, int c) {
    return (a != b and a != c and b != c) and (b > max(a, c) or b < min(a, c));
  };
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  FOR(i, N) FOR(k, M) FOR(d, 4) {
    int m = i * M + k;
    int x = i + dx[d], y = k + dy[d];
    int f = x * M + y;
    if (in(x, y)) {
      FOR(r, d + 1, 4) {
        int xx = i + dx[r], yy = k + dy[r];
        int t = xx * M + yy;
        if (in(xx, yy)) {
          if (ok(a[x][y], a[i][k], a[xx][yy])) {
            g.add(id[{f, m}], id[{m, t}]);
            g.add(id[{t, m}], id[{m, f}]);
          }
        }
      }
    }
  }
  int st = t, ed = t + 1;
  g.add(st, id[{0, 1}]);
  g.add(st, id[{0, M}]);
  int w = N * M - 1, e = N * M - 2, r = N * M - 1 - M;
  g.add(id[{e, w}], ed);
  g.add(id[{r, w}], ed);
  g.build();
  int ans = bfs1(g, st).fi[ed];
  print(ans == inf<int> ? -1 : ans - 1);
}
#include "YRS/aa/main.hpp"