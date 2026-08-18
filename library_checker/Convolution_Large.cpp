#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv_large.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N);
  VEC(mint, g, M);
  print(conv_large(f, g));
}

int main() {
  Yorisou();
  return 0;
}