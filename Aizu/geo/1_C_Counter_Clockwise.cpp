#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  PO(a, b);
  LL(q);
  FOR(q) {
    PO(c);
    if (segment(a, b).contain(c)) {
      UL("ON_SEGMENT");
      continue;
    }
    if (segment(a, c).contain(b)) {
      UL("ONLINE_FRONT");
      continue;
    }
    if (segment(b, c).contain(a)) {
      UL("ONLINE_BACK");
      continue;
    }
    ll o = ccw(a, b, c);
    UL(o == 1 ? "COUNTER_CLOCKWISE" : "CLOCKWISE");
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"