#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/his_max_add_set.hpp"

using AM = am_his_max_add_set<int>;
void Yorisou() {
  INT(N);
  segl_t<AM> seg(N, [&](int) -> PII {
    INT(x);
    return {x, x};
  });
  INT(Q);
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(l, r);
      --l;
      print(seg.prod(l, r).fi);
    } else if (op == 'A') {
      INT(l, r);
      --l;
      print(seg.prod(l, r).se);
    } else if (op == 'P') {
      INT(l, r, x);
      --l;
      seg.apply(l, r, AM::add(x));
    } else {
      INT(l, r, x);
      --l;
      seg.apply(l, r, AM::set(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}