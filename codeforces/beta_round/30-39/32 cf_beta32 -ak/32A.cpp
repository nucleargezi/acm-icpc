#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, n) FOR(k, i) ans += ABS(a[i] - a[k]) <= d;
  UL(ans << 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"