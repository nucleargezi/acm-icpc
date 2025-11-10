#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/xor.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using mono = monoid_xor<int>;
using LCT = LCT_monoid_commute<mono>;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  LCT lct(N);
  FOR(i, N) lct.set(i, a[i]);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x, --y;
      print(lct.prod(x, y));
    } else if (op == 1) {
      INT(x, y);
      --x, --y;
      if (lct.get_rt(x) != lct.get_rt(y)) lct.link(x, y);
    } else if (op == 2) {
      INT(x, y);
      --x, --y;
      lct.evert(x);
      if (lct.get_fa(y) == x) lct.cut(x, y);
    } else {
      INT(x, y);
      --x;
      lct.set(x, y);
    }
  }
}
#include "YRS/Z_H/main.hpp"