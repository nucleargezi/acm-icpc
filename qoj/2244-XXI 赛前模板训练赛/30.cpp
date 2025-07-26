#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  a = rearrange(a, convex_hull(a));
  n = len(a);
  RE ans = 0;
  FOR(i, n) {
    ans += dist<RE>(a[i], a[(i + 1) % n]);
  }
  print("{:.16f}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"