#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = n == 1 ? 1 : 2;
  FOR(i, 1, n - 1) if (a[i] > MAX(a[0], a[n - 1])) {
    ++ans;
    break;
  }
  FOR(i, 1, n - 1) if (a[i] < MIN(a[0], a[n - 1])) {
    ++ans;
    break;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"