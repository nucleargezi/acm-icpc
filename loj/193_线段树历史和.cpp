#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/his_sum_add.hpp"

using AM = am_his_sum_add<ll>;
void Yorisou() {
  INT(N, Q);
  segl_t<AM> seg(N, [&](int) {
    INT(x);
    return AM::X{x, x};
  });
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, AM::add(x));
    } else {
      print(seg.prod(l, r).hs);
    }
    seg.app(1, AM::tri());
  }
}

int main() {
  Yorisou();
  return 0;
}