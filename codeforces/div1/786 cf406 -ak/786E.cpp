#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_dense.hpp"
#include "YRS/gg/bs.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  FOR(i, N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  vc<int> d(N), fa(N), fe(N);
  Z ge = [&](Z &f, int n, int p) -> void {
    for (Z &&e : g[n]) if (e != p) {
      d[e] = d[n] + 1;
      fa[e] = n;
      fe[e] = e.id;
      f(f, e, n);
    }
  };
  ge(ge, 0, 0);

  vc<bs> gg(M, bs(N));
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    if (d[a] > d[b]) swap(a, b);
    while (d[a] < d[b]) gg[i].set(b), b = fa[b];
    while (a != b) gg[i].set(a), gg[i].set(b), a = fa[a], b = fa[b];
  }
  BM_dense f(gg, M, N);
  Z [x, y] = f.vcov();
  for (int &x : x) ++x;
  for (int &x : y) x = fe[x] + 1;
  print(si(x) + si(y));
  print(si(x), x);
  print(si(y), y);
}

int main() {
  Yorisou();
  return 0;
}