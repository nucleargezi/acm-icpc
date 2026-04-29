#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/count_c3c4.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc(M);
  print(count_C3C4(g).se);
}

int main() {
  Yorisou();
  return 0;
}