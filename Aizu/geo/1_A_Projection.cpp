#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using P = point<ll>;
using L = line<ll>;
using RE = long double;
void Yorisou() {
  PO(a, b);
  L l(a, b);
  LL(q);
  FOR(q) {
    PO(c);
    UL(toei<RE>(c, l));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"