#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/monge.hpp"

ll sq(ll x) { return x * x; }
void Yorisou() {
  INT(N, L);
  VEC(ll, a, N);
  a = pre_sum(a);
  Z f = [&](int l, int r) { return sq(a[r] - a[l] + r - l - 1 - L); };
  print(monge_dp_N<ll>(N, f));
}

int main() {
  Yorisou();
  return 0;
}