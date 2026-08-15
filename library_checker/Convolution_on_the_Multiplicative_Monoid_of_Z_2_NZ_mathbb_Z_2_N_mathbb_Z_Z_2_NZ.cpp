#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv_mul_2n.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, 1 << N);
  VEC(mint, g, 1 << N);
  print(conv_mul_2n(f, g));
}

int main() {
  Yorisou();
  return 0;
}