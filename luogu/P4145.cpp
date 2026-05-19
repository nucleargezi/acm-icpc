#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/beats/sum_sqrt.hpp"

using MX = Sum_sqrt;
void Yorisou() {
  INT(N);
  AngleBeats<MX> seg(N, [&](int) {
    LL(x);
    return MX::sing(x);
  });

  INT(Q);
  FOR(Q) {
    INT(op, l, r);
    if (l > r) swap(l, r);
    --l;
    if (op == 0) seg.apply(l, r, 1);
    else print(seg.prod(l, r).s);
  }
}

int main() {
  Yorisou();
  return 0;
}