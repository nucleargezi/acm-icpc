#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/18_polygon_area.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  RE res = polygon_area(a);
  std::cout << std::fixed << std::setprecision(1);
  UL(res / 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"