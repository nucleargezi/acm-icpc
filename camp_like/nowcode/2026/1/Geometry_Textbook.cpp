#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/exp/minkovski_sum_area.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N, M);
  VEC(P, a, N);
  VEC(P, b, M);
  setp(12);
  print(minkovski_sum_area(a, b));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}