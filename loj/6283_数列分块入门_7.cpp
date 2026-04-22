#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/al/m/affine.hpp"

using mint = mint_t<10007>;
using DS = seg_dual_t<monoid_affine<mint>>;
void Yorisou() {
  INT(N);
  DS seg(N);
  FOR(i, N) {
    INT(x);
    seg.apply(i, i + 1, {1, x});
  }
  
  FOR(N) {
    INT(op, l, r, x);
    --l;
    if (op == 0) seg.apply(l, r, {1, x});
    if (op == 1) seg.apply(l, r, {x, 0});
    if (op == 2) print(seg.get(r - 1).b);
  }
}

int main() {
  Yorisou();
  return 0;
}