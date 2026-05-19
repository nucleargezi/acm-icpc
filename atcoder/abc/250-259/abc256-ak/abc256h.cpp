#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/beats/sum_div_set.hpp"

using MX = Sum_div_set;
void Yorisou() {
  INT(N, Q);
  AngleBeats<MX> seg(N, [&](int) {
    LL(x);
    return MX::sing(x);
  });

  int x;
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) IN(x), seg.apply(l, r, MX::div(x));
    if (op == 2) IN(x), seg.apply(l, r, MX::set(x));
    if (op == 3) print(seg.prod(l, r).s);
  }
}

int main() {
  Yorisou();
  return 0;
}