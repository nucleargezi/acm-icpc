#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/19-polygon_contain.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  LL(q);
  FOR(q) {
    PO(p);
    UL(polygon_contain(a, p));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"