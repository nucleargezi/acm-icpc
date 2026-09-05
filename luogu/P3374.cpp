#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  seg_t<Add<ll>> seg(move(a));
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      seg.add(i - 1, x);
    } else {
      INT(l, r);
      print(seg.prod(l - 1, r));
    }
  }
}

int main() { Yorisou(); }