#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/tr_ecc.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  Z [c, id] = trecc(g);
  print(c);
  vc<vc<int>> v(N);
  FOR(i, N) v[id[i]].ep(i);
  FOR(i, N) if (si(v[i])) print(si(v[i]), v[i]);
}

int main() {
  Yorisou();
  return 0;
}