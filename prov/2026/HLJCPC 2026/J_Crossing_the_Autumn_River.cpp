#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  INT(N, K);
  VEC(int, d, N - 1);
  setp(9);
  print(SUM<re>(d) + re(K) / 4);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}