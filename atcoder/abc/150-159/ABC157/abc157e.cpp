#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/or.hpp"

void Yorisou() {
  INT(N);
  seg_t<Or<int>> seg(N, [&](int) {
    CH(c);
    return 1 << (c - 'a');
  });

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i);
      CH(c);
      seg.set(i - 1, 1 << (c - 'a'));
    } else {
      INT(l, r);
      print(pc(seg.prod(l - 1, r)));
    }
  }
}

int main() { Yorisou(); }