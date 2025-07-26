#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(T4<ll>, a, n);
  ll ans = 0;
  for (meion [a, b, c, d] : a) {
    if (a > c) ans += a - c;
    if (b > d) ans += b - d, ans += MIN(a, c);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"