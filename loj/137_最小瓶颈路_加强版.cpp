#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/tr/fast_lca.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
int A, B, C, P;
inline int rnd() { return A = (A * B + C) % P; }
void Yorisou() {
  INT(N, M);
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
  hld tr(g, t - 1);
  fast_lca v(tr);

  INT(Q);
  IN(A, B, C, P);
  mint s;
  FOR(Q) {
    int x = rnd() % N, y = rnd() % N;
    s += d[v.lca(x, y)];
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}