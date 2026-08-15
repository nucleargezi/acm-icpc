#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  print(a * b);
}

int main() {
  Yorisou();
  return 0;
}