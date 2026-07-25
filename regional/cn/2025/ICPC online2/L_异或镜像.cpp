#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_xor_copy.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_xor_copy<Add<ll>> seg({all(a)});
  FOR(Q) {
    INT(op, l, r);
    if (op == 1) {
      INT(k);
      seg.copy(l, r, k);
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}