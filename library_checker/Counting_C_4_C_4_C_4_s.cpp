#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/c3/count_c4.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, es, M);
  print(count_c4(N, es));
}

int main() {
  Yorisou();
  return 0;
}