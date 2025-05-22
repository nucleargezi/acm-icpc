#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/pre_max_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, q);
  pre_max_seg<pair<RE, int>, monoid_add<int>> seg(n);
  FOR(q) {
    LL(x, y);
    seg.set(x - 1, {pair{RE(y) / x, -x}, 1});
    UL(seg.prod_all());
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"