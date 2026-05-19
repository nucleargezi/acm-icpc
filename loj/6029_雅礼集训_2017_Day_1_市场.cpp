#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/beats/sum_div_add.hpp"

using MX = Sum_div_add;
void Yorisou() {
  INT(N, Q);
  AngleBeats2<MX> seg(N, [&](int) {
    LL(x);
    return MX::sing(x);
  });

  int x;
  FOR(Q) {
    INT(op, l, r);
    ++r;
    if (op == 1) IN(x), seg.apply(l, r, MX::add(x));
    if (op == 2) IN(x), seg.apply(l, r, MX::div(x));
    if (op == 3) print(seg.prod(l, r).l);
    if (op == 4) print(seg.prod(l, r).s);
  }
}

int main() {
  Yorisou();
  return 0;
}