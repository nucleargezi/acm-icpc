#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/sqrt.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(sqrt(f));
}

int main() {
  Yorisou();
  return 0;
}