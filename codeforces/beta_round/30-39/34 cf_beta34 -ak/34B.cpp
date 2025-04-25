#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  sort(a);
  ll ans = 0;
  FOR(i, MIN(n, m)) ans += MAX(-a[i], 0ll);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"