#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/inversion.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  print(inversion(a));
}

int main() {
  Yorisou();
  return 0;
}