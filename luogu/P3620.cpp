#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/candy_dp.hpp"

void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  sort(a);
  FOR_R(i, 1, N) a[i] -= a[i - 1];
  a.erase(bg(a));
  print(candy_dp(a)[K]);
}

int main() {
  Yorisou();
  return 0;
}