#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/scc.hpp"

void Yorisou() {
  INT(N, M);
  graph<int, 1> g(N);
  g.sc<0, 0>(M);
  Z [T, id] = scc(g);
  print(T);
  for (Z a : get_scc_group(T, id)) print(si(a), a);
}

int main() {
  Yorisou();
  return 0;
}