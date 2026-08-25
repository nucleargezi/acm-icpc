#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/minidx.hpp"

void Yorisou() {
  INT(N);
  seg_t<Minidx<int>> seg(N, [&](int i) {
    INT(x);
    return PII{x, i};
  });
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.set(i, {x, i});
    } else {
      INT(l, r);
      --l;
      print(seg.prod(l, r).fi);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}