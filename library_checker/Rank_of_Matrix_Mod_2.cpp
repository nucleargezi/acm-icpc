#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/mat_rank.hpp"

void Yorisou() {
  INT(N, M);
  print(mat_rank2(N, M, fio::fin));
}

int main() {
  Yorisou();
  return 0;
}