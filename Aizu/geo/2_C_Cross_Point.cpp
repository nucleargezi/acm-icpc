#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  FOR(i, n) {
    PO(a, b, c, d);
    L x(a, b), y(c, d);
    UL(cross_point(x, y));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"