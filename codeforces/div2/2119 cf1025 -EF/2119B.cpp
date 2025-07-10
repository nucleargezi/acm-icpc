#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, x, y, xx, yy);
  VEC(ll, a, n);
  ll s = SUM(a), m = QMAX(a);
  ll l = MAX(0ll, m * 2 - s), r = s;
  l *= l, r *= r;
  ll d = (xx - x) * (xx - x) + (yy - y) * (yy - y);
  Yes(l <= d and d <= r);
}
#include "MeIoN_Lib/Z_H/main.hpp"