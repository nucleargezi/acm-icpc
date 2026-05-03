#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc(M);
  B_matching f(g);
  f.matching();
  Z [c, w] = f.DM_dec();
  vc<int> sz(N + 1);
  FOR(i, N) ++sz[w[i]];
  vc<PII> es;
  for (Z &&e : g.es) {
    int a = e.f, b = e.to;
    if (a > b) swap(a, b);
    if (f.mat[a] == b and w[a] == w[b] and sz[w[a]] == 2) es.ep(a + 1, b + 1);
  }
  sort(es);
  print(si(es));
  for (var [a, b] : es) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}