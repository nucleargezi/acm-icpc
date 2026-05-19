#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/lis.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  print(lis_dp(a).fi);
}

int main() {
  Yorisou();
  return 0;
}