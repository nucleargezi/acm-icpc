#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/tr_ecc.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc(M);
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