#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/tr_ecc.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  Z [c, id] = trecc(g);
  print(c);
  vc<vc<int>> v(N);
  FOR(i, N) v[id[i]].ep(i + 1);
  FOR(i, N) sort(v[i]);
  sort(v);
  FOR(i, N) if (si(v[i])) print(v[i]);
}

int main() {
  Yorisou();
  return 0;
}