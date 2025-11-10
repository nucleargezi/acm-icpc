#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_monoid_sub.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using LCT = LCT_monoid_sub<monoid_add<int>>;
void Yorisou() {
  INT(N, Q);
  LCT lct(N);
  FOR(i, N) lct.a[i].mx = 1;
  FOR(Q) {
    CH(op);
    INT(x, y);
    --x, --y;
    if (op == 'A') lct.link(x, y);
    else print(1ll * lct.prod(x, y) * lct.prod(y, x));
  }
}
#include "YRS/Z_H/main.hpp"