#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 0;
  ll mx = QMAX(a);
  bool f = 0;
  f |= mx == a[0] or mx == a[n - 1];
  if (f) {
    if (n > 2) ans = mx * (n - 2);
  } else {
    if (n > 2) ans = mx * (n - 3) + std::max(a[0], a[n - 1]);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"