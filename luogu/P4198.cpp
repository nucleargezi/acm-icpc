#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/premax_seg.hpp"
#include "YRS/al/m/add.hpp"

using re = double;
void Yorisou() {
  INT(N, Q);
  premax_seg<re, Add<int>, 1> seg(N);
  FOR(Q) {
    INT(x, y);
    seg.set(x - 1, {re(y) / x, 1});
    print(seg.prod());
  }
}

int main() {
  Yorisou();
  return 0;
}