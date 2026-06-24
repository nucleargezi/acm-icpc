#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/scc.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b);
  }
  Z [T, id] = scc(g);
  vc<vc<int>> v(T);
  FOR(i, N) v[id[i]].ep(i);
  print(T);
  for (var s : v) print(si(s), s);
}

int main() {
  Yorisou();
  return 0;
}