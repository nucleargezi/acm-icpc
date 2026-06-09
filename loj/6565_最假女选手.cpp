#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/anglebeats.hpp"
#include "YRS/al/beats/sum_add_ch.hpp"

using MX = Sum_add_ch<ll>;
void Yorisou() {
  INT(N);
  AngleBeats<MX> seg(N, [&](int i) {
    LL(x);
    return MX::sing(x);
  });

  INT(Q);
  int op, l, r, x;
  FOR(Q) {
    IN(op, l, r);
    if (op <= 3) IN(x);
    --l;
    if (op == 1) seg.apply(l, r, MX::add(x));
    else if (op == 2) seg.apply(l, r, MX::cmax(x));
    else if (op == 3) seg.apply(l, r, MX::cmin(x));
    else if (op == 4) print(seg.prod(l, r).s);
    else if (op == 5) print(seg.prod(l, r).mx);
    else if (op == 6) print(seg.prod(l, r).mn);
  }
}

int main() {
  Yorisou();
  return 0;
}