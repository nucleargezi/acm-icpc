#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  meion b = a;
  unique(b);
  if (len(a) != len(b)) iroha No();
  Yes(n == len(convex_hull<ll, 0>(a)));
}
#include "MeIoN_Lib/Z_H/main.hpp"