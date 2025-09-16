#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  constexpr PLL d[]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  FOR(i, n) {
    for (meion d : d) {
      a.emplace_back(a[i] + d);
    }
  }
  a = rearrange(a, convex_hull(a));
  n = len(a);
  a += a[0];
  ll ans = 0;
  FOR(i, n) {
    meion [x, y] = a[i] - a[i + 1];
    ans += MAX(ABS(x), ABS(y));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"