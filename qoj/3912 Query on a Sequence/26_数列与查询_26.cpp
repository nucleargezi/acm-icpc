#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/sum_add_ch.hpp"

using beats = Sum_add_ch<ll>;
void Yorisou() {
  INT(N);
  AngelBeats<beats> seg(N, [&](int i) -> beats::X {
    INT(x);
    return beats::sing(x);
  });
  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, beats::cmin(x));
    } else if (op == 2) {
      print(seg.prod(l, r).mx);
    } else {
      print(seg.prod(l, r).s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}