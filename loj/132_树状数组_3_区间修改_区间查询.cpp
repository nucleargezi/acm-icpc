#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/range_sumadd.hpp"
#include "YRS/al/m/add.hpp"

using DS = range_sum_add<ll>;
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
      INT(l, r);
      --l;
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}