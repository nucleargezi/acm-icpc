#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/fun/convex_corner_area.hpp"

// #define tests
using P = point<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  UL(convex_corner_area<RE>(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"