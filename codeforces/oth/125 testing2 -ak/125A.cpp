#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  if (N % 3 == 1) --N;
  else if (N % 3) N += 2;
  print(N / 36, N % 36 / 3);
}

int main() {
  Yorisou();
  return 0;
}