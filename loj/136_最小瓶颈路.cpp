#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/g/Basic.hpp"

TE struct doubling {
  using G = graph<T, 0>;
  int N, n, t = 0;
  G &g;
  retsu<int> fa;
  vc<int> d;

  void f(int n, int p) {
    fa[0][n] = p;
    d[n] = p == n ? 0 : d[p] + 1;
    for (Z &&e : g[n]) if (e.to != p) f(e.to, n);
  }

  doubling(G &g, int r = 0) : N(g.N), n(topbit(N) + 1), g(g), fa(n, N, -1), d(N) {
    FOR_R(i, N) if (fa[0][i] == -1) f(i, i);
    FOR(i, 1, n) FOR(k, N) fa[i][k] = fa[i - 1][fa[i - 1][k]];
  }

  int lca(int a, int b) {
    if (d[a] < d[b]) swap(a, b);
    int w = d[a] - d[b];
    FOR(i, n) if (w >> i & 1) a = fa[i][a];
    if (a == b) return a;
    FOR_R(i, n) {
      int x = fa[i][a], y = fa[i][b];
      if (x != y) a = x, b = y;
    }
    return fa[0][a];
  }
};
void Yorisou() {
  INT(N, M, Q);
  VEC(T3<int>, e, M);
  sort(e, [&](var a, var b) { return get<2>(a) < get<2>(b); });
  int t = N;
  dsu f(N + N - 1);
  vc<int> d(N + N - 1);
  graph g(N + N - 1);
  for (Z [x, y, w] : e) {
    --x, --y;
    x = f[x], y = f[y];
    if (x == y) continue;
    g.add(t, x);
    g.add(t, y);
    f.set(t, x);
    f.set(t, y);
    d[t] = w;
    t++;
  }
  g.build();
  doubling v(g);
  FOR(Q) {
    INT(x, y);
    --x, --y;
    if (f[x] == f[y]) print(d[v.lca(x, y)]);
    else print(-1);
  }
}

int main() {
  Yorisou();
  return 0;
}