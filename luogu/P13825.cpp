#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segdl_def_t.hpp"
#include "YRS/al/am/sum_add.hpp"

using AM = a_monoid_sum_add<ull>;
struct def {
  ull dprod(int l, int r) { return ull(r - l) * (l + r + 1) / 2; }
};
using DS = segdl_def_t<def, AM, 0, int, 8>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS seg(0, N);
  np t = seg.newnode();
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      t = seg.apply(t, l, r, x);
    } else {
      print(seg.prod(t, l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}