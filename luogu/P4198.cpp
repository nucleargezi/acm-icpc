#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_premax_t.hpp"
#include "YRS/al/m/add.hpp"

using re = double;
using MX = Add<int>;
void Yorisou() {
  INT(N, Q);
  seg_premax_t<re, MX> seg(N);
  FOR(Q) {
    INT(x, y);
    seg.set(x - 1, {re(y) / x, 1});
    print(seg.prod(0, N));
  }
}

int main() {
  Yorisou();
  return 0;
}