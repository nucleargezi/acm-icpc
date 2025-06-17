#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/11-in_circle.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  PO(a, b, c);
  meion [o, r] = in_circle<RE>(a, b, c);
  UL(o);
  UL(r);
}
#include "MeIoN_Lib/Z_H/main.hpp"