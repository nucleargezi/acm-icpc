#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/comp_inv.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(comp_inv(f));
}

int main() {
  Yorisou();
  return 0;
}