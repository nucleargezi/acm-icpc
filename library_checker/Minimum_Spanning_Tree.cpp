#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/mst_kru.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<1, 0>(M);
  Z [s, v] = mst_kru(g);
  print(s);
  print(v);
}

int main() {
  Yorisou();
  return 0;
}