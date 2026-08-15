#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/shift.hpp"

using mint = M99;
void Yorisou() {
  INT(N, K);
  VEC(mint, f, N);
  print(shift(f, K));
}

int main() {
  Yorisou();
  return 0;
}