#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N);
  if (N & 1) print(0);
  else print(N / 2 * (N - 2));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}