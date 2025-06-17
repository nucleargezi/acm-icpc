#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/8-distance.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  LL(n);
  FOR(i, n) {
    PO(a, b, c, d);
    UL(distance<RE>(segment(a, b), segment(c, d)));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"