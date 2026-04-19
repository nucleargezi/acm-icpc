#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/mst_kru.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<1>(M);
  print(mst_kru(g).fi);
}

int main() {
  Yorisou();
  return 0;
}