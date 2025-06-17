#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  meion hull = convex_hull<ll, 1>(a);
  UL(len(hull));
  PLL mn{inf<ll>, inf<ll>};
  int p = -1;
  FOR(i, len(hull)) {
    if (chmin(mn, PLL(a[hull[i]].y, a[hull[i]].x))) {
      p = i;
    }
  }
  std::ranges::rotate(hull, hull.begin() + p);
  for (int i : hull) {
    UL(a[i]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"