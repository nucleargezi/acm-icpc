#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/order/order3.hpp"

void Yorisou() {
  INT(N, K);
  vc<array<int, 3>> a(N);
  FOR(i, N) IN(a[i][0], a[i][1], a[i][2]);
  vc<int> rs(N);
  for (int x : order3(a, K)()) ++rs[x];
  FOR(i, N) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}