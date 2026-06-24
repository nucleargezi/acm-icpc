#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/sum_affine.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(mint, a, N);
  segl_t<Sum_affine<mint>> seg(a);

  FOR(Q) {
    INT(op, l, r);
    if (op == 0) {
      INT(a ,b);
      seg.apply(l, r, {a, b});
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}