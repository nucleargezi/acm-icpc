#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/exlucas.hpp"

void Yorisou() {
  LL(N, M, P);
  print(exlucas(N, M, P));
}

int main() {
  Yorisou();
  return 0;
}