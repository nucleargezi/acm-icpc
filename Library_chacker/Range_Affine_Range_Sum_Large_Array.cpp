#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/seg/segdl_t.hpp"
#include "YRS/al/am/sum_affine.hpp"

using mint = M99;
using AM = a_monoid_sum_affine<mint>;
using DS = segdl_t<AM, 0, int>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS seg(0, N);
  np t{};
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(l, r, a, b);
      t = seg.apply(t, l, r, {a, b});
    } else {
      INT(l, r);
      print(seg.prod(t, l, r));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"