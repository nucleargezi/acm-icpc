#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll s = SUM(a);
  ll t = s / ((1 + n) * n / 2);
  int x = binary_search<false>([&](ll x) -> bool {
    iroha t - x + x * n <= a[0];
  }, 0, t + 1), y = t - x;
  FOR(i, n) if (y * (i + 1) + x * (n - i) != a[i]) iroha NO();
  YES();
}
#include "MeIoN_Lib/Z_H/main.hpp"