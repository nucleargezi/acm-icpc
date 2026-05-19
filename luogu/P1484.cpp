#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/candy_dp.hpp"

void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  FOR(i, N) a[i] = -a[i];
  a = candy_dp(a);
  while (si(a) > K + 1) pop(a);
  print(-QMIN(a));
}

int main() {
  Yorisou();
  return 0;
}