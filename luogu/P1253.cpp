#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/max_affine.hpp"

using MX = Max_affine<ll>;
using DS = segl_t<MX>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS seg(a);
  int x;
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) IN(x), seg.apply(l, r, {0, x});
    if (op == 2) IN(x), seg.apply(l, r, {1, x});
    if (op == 3) print(seg.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}