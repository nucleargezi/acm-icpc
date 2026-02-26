#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph g(N + N);
  g.read_graph(M);
  dsu f(N + N);
  for (Z &&e : g.edges) {
    f.merge(e.f, e.to);
  }
  vc<int> deg = g.deg_array();
  retsu<u8> c(N, N);
  vc<int> s;
  s.reserve(N);
  FOR(i, N) {
    s.clear();
    for (Z &&e : g[i]) s.ep(e.to - N);
    int sz = len(s);
    FOR(i, sz) FOR(k, i + 1, sz) {
      int x = s[i], y = s[k];
      if (x > y) swap(x, y);
      if (c[x][y]) return print(2);
      c[x][y] = 1;
    }
  }
  FOR(i, N + N) if (deg[i] > 1) {
    for (Z &&e : g[i]) {
      if (deg[e.to] > 1) return print(3);
    }
  }
  FOR(i, N + N) if (deg[i] > 2) return print(3);
  FOR(i, N + N) if (deg[i] > 2 and N > 2) return print(4);
  FOR(i, N + N) if (deg[i] > 1) return print(4);
  int cn = 0, cc = 0;
  FOR(i, N) if (deg[i] > 0) ++cn;
  FOR(i, N, N + N) if (deg[i] > 0) ++cc;
  if (cn >= 2 or cc >= 2) return print(4);
  if (cn >= 1 or cc >= 1) return print(5);
  print(6);
}
#include "YRS/aa/main.hpp"