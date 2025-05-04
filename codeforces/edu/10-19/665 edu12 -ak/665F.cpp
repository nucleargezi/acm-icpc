#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/prime_sum.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  prime_sum<ll> F(n);
  F.calc_count();
  meion prim = primtable(1'000'001);
  ll ans = 0;
  for (ll p : prim) {
    if (p * p * p > n) break;
    ++ans;
  }
  FOR(i, len(prim)) {
    ans += MAX(0ll, F[n / prim[i]] - i - 1);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"