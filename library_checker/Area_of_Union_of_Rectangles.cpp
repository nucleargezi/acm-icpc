#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/rectangle_union.hpp"

// #define tests
void Yorisou() {
  LL(n);
  rectangle_union<ll> seg;
  FOR(n) {
    LL(x, y, xx, yy);
    seg.add(x, y, xx, yy);
  }
  UL(seg.keisan());
}
#include "MeIoN_Lib/Z_H/main.hpp"