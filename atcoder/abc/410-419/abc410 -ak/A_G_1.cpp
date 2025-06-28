#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  LL(k);
  ll ans = 0;
  FOR(i, n) ans += k <= a[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"