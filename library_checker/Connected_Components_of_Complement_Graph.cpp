#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/cc_of_comp_g.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  Z [c, id] = cc_of_comp_g(g);
  print(c);
  vc<vc<int>> s(c);
  FOR(i, N) s[id[i]].ep(i);
  FOR(i, c) print(si(s[i]), s[i]);
}

int main() {
  Yorisou();
  return 0;
}