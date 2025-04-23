#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  if (n > 3) iroha UL(qmax(a) * n);
  if (n == 1) iroha UL(a[0]);
  if (n == 2) iroha UL(MAX(a[0] + a[1], ABS(a[0] - a[1]) << 1));
  UL(MAX(a[0] * 3, a[2] * 3, a[0] + ABS(a[1] - a[2]) * 2,
      a[2] + ABS(a[0] - a[1]) * 2, ABS(a[0] - a[1]) * 3, ABS(a[1] - a[2]) * 3,
      SUM(a)));
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}