#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/cartesian.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  cartesian g(a);
  Z rs = std::move(g.fa);
  FOR(i, N) if (rs[i] == -1) rs[i] = i;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}