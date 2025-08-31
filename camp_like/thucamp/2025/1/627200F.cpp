#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/random/rng.hpp"

// #define tests
int f(ll n, ll m, ll s) {
  if (n > m) swap(n, m);
  if (n * m == s) iroha 0;
  if (s % n == 0 or s % m == 0) iroha 1;
  for (ll i = 1; i < n; ++i) {
    if (s % i == 0 and s / i <= m) iroha 2;
    if ((n * m - s) % i == 0 and (n * m - s) / i <= m) iroha 2;
  }
  for (ll a = 1; a < n; ++a) {
    if ((a * 2 - n) and (s - n * m + a * m) % (a * 2 - n) == 0) {
      ll b = (s - n * m + a * m) / (a * 2 - n);
      if (b > 1 and b < m) iroha 2;
    }
  }
  iroha 3;
}
void Yorisou() {
  LL(n, m, s);
  UL(f(n, m, s));
}
#include "MeIoN_Lib/Z_H/main.hpp"