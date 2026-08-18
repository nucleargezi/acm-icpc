#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/conv/min_plus_conv.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(int, b, M);
  print(min_plus_conv_cc_a(a, b));
}

int main() {
  Yorisou();
  return 0;
}