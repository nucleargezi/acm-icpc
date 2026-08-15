#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/order/order_bs.hpp"

using T = array<int, 4>;
void Yorisou() {
  INT(N, Q);
  VEC(T, a, N);
  VEC(T, q, Q);
  for (Z &a : a) a[2] = -a[2], a[3] = -a[3];
  for (Z &a : q) a[2] = -a[2], a[3] = -a[3];
  order_bs<4> g(a);
  for (int x : g(q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}