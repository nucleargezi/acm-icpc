#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/inv.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(inv(f));
}

int main() {
  Yorisou();
  return 0;
}