#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/sum_add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  segl_t<Sum_add<ll>> seg(move(a));
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      LL(x);
      seg.apply(l, r, x);
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() { Yorisou(); }