#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, 0, n, 2) ans += a[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"