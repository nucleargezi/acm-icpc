#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/range_copy.hpp"
#include "YRS/al/am/sum_add.hpp"

using MX = Sum_add<ll>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  range_copy<MX> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, x);
    } else if (op == 2) {
      INT(c, d);
      --c;
      seg.copy(l, r, c, d);
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}