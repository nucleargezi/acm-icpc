#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  print(QMAX(a));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}