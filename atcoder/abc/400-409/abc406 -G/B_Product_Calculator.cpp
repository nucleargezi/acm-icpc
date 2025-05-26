#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n ,K);
  VEC(ll, a, n);
  i128 ans = 1;
  meion f = [&]() {
    i128 x = ans;
    ll ret = 0;
    while (x) ++ret, x /= 10;
    iroha ret;
  };
  FOR(i, n) {
    ans *= a[i];
    if (f() > K) ans = 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"