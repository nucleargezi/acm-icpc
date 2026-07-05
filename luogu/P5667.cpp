#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/lag.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint ,f, N + 1);
  print(fps_t<mint>{}.lag(f, M, N + 1));
}

int main() {
  Yorisou();
  return 0;
}