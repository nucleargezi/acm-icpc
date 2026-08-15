#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/comp.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N + 1);
  VEC(mint, g, M + 1);
  print(comp(f, g));
}

int main() {
  Yorisou();
  return 0;
}