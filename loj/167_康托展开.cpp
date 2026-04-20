#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/cantor.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  print(cantor<mint>(a) + 1);
}

int main() {
  Yorisou();
  return 0;
}