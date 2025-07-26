#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/geo/4-closest_pair.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  meion [x, y] = closest_pair(a);
  print("{:.12f}", dist(a[x], a[y]));
}
#include "MeIoN_Lib/Z_H/main.hpp"