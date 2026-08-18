#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/range_linear_add_min.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_linear_add_min<ll> seg({all(a)});
  FOR(Q) {
    INT(op, l, r);
    if (op == 0) {
      INT(b, c);
      seg.apply(l, r, b, c);
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}