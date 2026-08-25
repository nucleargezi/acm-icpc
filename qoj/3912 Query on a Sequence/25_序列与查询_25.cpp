#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/max_and_or.hpp"

using beats = Max_and_or<int>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  AngelBeats<beats> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, beats::band(x));
    } else if (op == 2) {
      INT(x);
      seg.apply(l, r, beats::bor(x));
    } else {
      print(seg.prod(l, r).mx);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}