#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/sum_affine.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
using DS = segl_t<Sum_affine<mint>>;
void Yorisou() {
  INT(N);
  VEC(mint, a, N);
  DS seg(a);
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op <= 3) {
      INT(x);
      if (op == 1) seg.apply(l, r, {1, x});
      if (op == 2) seg.apply(l, r, {x, 0});
      if (op == 3) seg.apply(l, r, {0, x});
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}