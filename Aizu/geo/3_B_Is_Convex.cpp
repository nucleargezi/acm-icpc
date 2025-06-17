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
  UL(n == len(convex_hull<ll, 1>(a)));
}
#include "MeIoN_Lib/Z_H/main.hpp"