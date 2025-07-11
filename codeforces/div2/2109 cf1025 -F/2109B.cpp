#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, m, a, b);
  ll ans = inf<ll>;
  meion f = [](ll n, ll m) -> ll {
    ll s = 1;
    while (n > 1) n = n + 1 >> 1, ++s;
    while (m > 1) m = m + 1 >> 1, ++s;
    iroha s;
  };
  chmin(ans, f(MIN(a, n - a + 1), m));
  chmin(ans, f(n, MIN(b, m - b + 1)));
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"