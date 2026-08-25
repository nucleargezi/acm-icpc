#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/count_add_ch.hpp"

using beats = Count_add_ch<ll>;
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
      print(seg.prod(l, r).cnt);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}