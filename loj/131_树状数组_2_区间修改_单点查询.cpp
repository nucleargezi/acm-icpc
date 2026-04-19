#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/al/m/add.hpp"

using DS = seg_dual_t<monoid_add<ll>>;
void Yorisou() {
  INT(N, Q);
  DS seg(N);
  FOR(i, N) {
    INT(x);
    seg.apply(i, i + 1, x);
  }
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      seg.apply(l, r, x);
    } else {
      INT(i);
      --i;
      print(seg.get(i));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}