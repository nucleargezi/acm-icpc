#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/range_sp_point_ins.hpp"

void Yorisou() {
  INT(Q, N);
  range_sp_point_ins<int, 31> seg(N);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.add(i, x);
    } else {
      INT(l, r);
      --l;
      print(seg.prod(l, r).max());
    }
  }
}

int main() {
  Yorisou();
  return 0;
}