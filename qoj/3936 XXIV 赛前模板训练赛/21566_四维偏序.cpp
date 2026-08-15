#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/order/order_bs.hpp"

using T = array<int, 4>;
void Yorisou() {
  INT(N);
  VEC(T, a, N);
  ll s = 0;
  for (int x : order_bs<4, 1>(a)(a)) s += x;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}