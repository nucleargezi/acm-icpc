#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/dij.hpp"

void Yorisou() {
  INT(N, L);
  VEC(T4<int>, es, N);
  vc<int> f{0, L};
  for (var [x, d, t, p] : es) {
    f.ep(x);
    if (x - p >= 0) f.ep(x - p), f.ep(x + d);
  }
  unique(f);
  int n = si(f);

  vc<vc<edge_w<ll>>> g(n + N);
  FOR(i, N) {
    var [x, d, t, p] = es[i];
    if (x - p >= 0) {
      int fr = lb(f, x - p), m = i + n, to = lb(f, x + d);
      g[fr].ep(m, 0), g[m].ep(to, p + t);
    }
  }
  FOR(i, 1, n) {
    int a = f[i - 1], b = f[i];
    g[i - 1].ep(i, b - a);
    g[i].ep(i - 1, b - a);
  }

  Z [d, fa] = dij<ll>(g, 0);
  vc<int> s;
  for (int x = n - 1; x != -1; x = fa[x]) {
    if (x >= n) s.ep(x - n + 1);
  }
  reverse(s);
  print(d[n - 1]);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}