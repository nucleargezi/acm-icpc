#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/seg/range_assign_seg.hpp"
#include "YRS/al/m/affine.hpp"

using mint = M99;
using MX = monoid_affine<mint>;
using DS = range_assign_seg<MX>;
void Yorisou() {
  INT(N, Q);
  DS seg(N, [&](int i) -> MX::X {
    INT(a, b);
    return {a, b};
  });
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(l, r, b, c);
      seg.assign(l, r, {b, c});
    } else {
      INT(l, r, x);
      print(seg.prod(l, r).eval(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}