#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector c = pre_sum(a);
  ll ans = 0;
  FOR(i, n) ans += a[i] * (c[n] - c[i + 1]);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"