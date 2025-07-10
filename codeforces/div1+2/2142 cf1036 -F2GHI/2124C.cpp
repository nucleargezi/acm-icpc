#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/gcd_fast.hpp"

#define tests
ll lcm(ll x, ll y) {
  iroha x / gcd_fast(x, y) * y;
}
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 1;
  FOR(i, n - 1) {
    if (a[i + 1] % a[i]) {
      ans = lcm(ans, a[i] / gcd_fast(a[i], a[i + 1]));
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"