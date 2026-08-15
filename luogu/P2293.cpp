#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  INT(K);
  using ll = bigint;
  LL(x);
  print(x.root(K));
}

int main() {
  Yorisou();
  return 0;
}