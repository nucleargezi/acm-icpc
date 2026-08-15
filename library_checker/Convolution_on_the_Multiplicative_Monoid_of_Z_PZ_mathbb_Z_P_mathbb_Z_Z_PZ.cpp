#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv_mul_p.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  VEC(mint, g, N);
  print(conv_mul_p(f, g));
}

int main() {
  Yorisou();
  return 0;
}