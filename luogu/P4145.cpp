#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/basic/fast_set.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using DS = Seg<monoid_add<ll>>;
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  DS seg(a);
  fast_set se(N);
  FOR(i, N) if (a[i] > 1) se.eb(i);
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    if (l > r) swap(l, r);
    --l;
    if (op == 0) {
      for (int i = se.next(l); i < r; i = se.next(i + 1)) {
        a[i] = sqrtl(a[i]);
        if (a[i] == 1) se.extract(i);
        seg.set(i, a[i]);
      }
    } else {
      print(seg.prod(l, r));
    }
  }
}
#include "YRS/Z_H/main.hpp"