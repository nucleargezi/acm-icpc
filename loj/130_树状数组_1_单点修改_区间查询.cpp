#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/add.hpp"

using DS = seg_t<monoid_add<ll>>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS seg(a);
  FOR(Q) {
    INT(op, a, b);
    if (op == 1) seg.multiply(a - 1, b);
    else print(seg.prod(a - 1, b));
  }
}

int main() {
  Yorisou();
  return 0;
}