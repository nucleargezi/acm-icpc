#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats2.hpp"
#include "YRS/al/beats/sum_sqrt_add.hpp"

using beats = Sum_sqrt_add;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  AngelBeats2<beats> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, beats::add(x));
    } else if (op == 2) {
      seg.apply(l, r, beats::sq());
    } else {
      print(seg.prod(l, r).s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}