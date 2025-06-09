#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  sort(a, greater());
  ll ans = 0;
  FOR(i, n) {
    if (a[i] >= i + 1) ans = i + 1;
    else break;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"