#include "YRS/all.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  Seg<monoid_add<ll>> seg(a);
  FOR(q) {
    LL(op, x, y);
    if (op == 0) {
      seg.multiply(x, y);
    } else {
      print(seg.prod(x, y));
    }
  }
}
#include "YRS/Z_H/main.hpp"