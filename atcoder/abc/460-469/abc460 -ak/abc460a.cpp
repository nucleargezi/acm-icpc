#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  int s = 1;
  for (; N % M != 0; M = N % M, ++s);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}