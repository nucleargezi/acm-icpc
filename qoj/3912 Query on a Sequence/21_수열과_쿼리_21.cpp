#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  seg_dual<Add<ll>> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      seg.apply(l, r, x);
    } else {
      INT(x);
      --x;
      print(seg[x]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}