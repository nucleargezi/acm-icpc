#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/cartesian.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  cartesian<int, 1> s(a);
  a = s.fa;
  a[s.t] = s.t;
  print(a);
}

int main() {
  Yorisou();
  return 0;
}