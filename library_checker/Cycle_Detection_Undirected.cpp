#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/find_min_cycle.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  Z [vs, es] = find_min_cycle(g);
  if (es.empty()) return print(-1);
  print(si(vs));
  print(vs);
  print(es);
}

int main() {
  Yorisou();
  return 0;
}