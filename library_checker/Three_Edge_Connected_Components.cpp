#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/tr_ecc.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b), g[b].ep(a);
  }
  Z [c, id] = trecc(g);
  vc<vc<int>> v(N);
  FOR(i, N) v[id[i]].ep(i);
  print(c);
  FOR(i, N) if (si(v[i])) print(si(v[i]), v[i]);
}

int main() {
  Yorisou();
  return 0;
}