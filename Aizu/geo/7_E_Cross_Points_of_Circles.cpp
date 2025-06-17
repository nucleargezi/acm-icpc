#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  circle<RE> a, b;
  IN(a.O, a.r);
  IN(b.O, b.r);
  meion [ok, x, y] = cross_point_circle<RE>(a, b);
  if (x > y) swap(x, y);
  UL(x, y);
}
#include "MeIoN_Lib/Z_H/main.hpp"