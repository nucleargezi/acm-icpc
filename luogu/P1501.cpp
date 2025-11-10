#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_act.hpp"
#include "YRS/ds/a_monoid/sum_affine.hpp"
#include "YRS/math/mod/modint.hpp"

using mint = modint<51061>;
using LCT = LCT_act_commute<a_monoid_sum_affine<mint>>;
using MA = LCT::AM::MA;
void Yorisou() {
  INT(N, Q);
  LCT lct(N, [&](int)  { return 1; });
  FOR(N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  FOR(Q) {
    CH(op);
    if (op == '+') {
      INT(x, y, c);
      --x, --y;
      lct.apply(x, y, MA::make_add(c));
    } else if (op == '-') {
      INT(x, y, xx, yy);
      --x, --y, --xx, --yy;
      lct.cut(x, y), lct.link(xx, yy);
    } else if (op == '*') {
      INT(x, y, c);
      --x, --y;
      lct.apply(x, y, {c, 0});
    } else {
      INT(x, y);
      --x, --y;
      print(lct.prod(x, y).val);
    }
  }
}
#include "YRS/Z_H/main.hpp"