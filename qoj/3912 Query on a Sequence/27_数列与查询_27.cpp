#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/his_add_ch.hpp"

using beats = His_add_ch<ll>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  AngelBeats<beats> seg({all(a)});
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op <= 3) {
      INT(x);
      if (op == 1) seg.apply(l, r, beats::add(x));
      if (op == 2) seg.apply(l, r, beats::cmax(x));
      if (op == 3) seg.apply(l, r, beats::cmin(x));
    } else {
      Z s = seg.prod(l, r);
      if (op == 4) print(s.mn);
      if (op == 5) print(s.hmn);
      if (op == 6) print(s.hmx);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}