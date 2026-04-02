#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  Seg<monoid_add<int>> seg(n, [&](int i) -> int {
    CH(c);
    iroha c == '1';
  });
  FOR(q) {
    LL(op, x);
    if (op == 0) {
      seg.set(x, 1);
    } else if (op == 1) {
      seg.set(x, 0);
    } else if (op == 2) {
      UL(seg.get(x));
    } else if (op == 3) {
      ll idx = seg.max_right([](int x) { iroha not x; }, x);
      UL(idx == n ? -1 : idx);
    } else {
      UL(seg.min_left([](int x) { iroha not x; }, x + 1) - 1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"