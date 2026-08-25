#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/sum_div_add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  AngelBeats<Sum_div_add> seg({all(a)});
  FOR(Q) {
    INT(op, l, r);
    ++r;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, {0, x});
    } else if (op == 2) {
      INT(x);
      seg.apply(l, r, {1, x});
    } else if (op == 3) {
      print(seg.prod(l, r).l);
    } else {
      print(seg.prod(l, r).s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}