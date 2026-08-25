#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/add_array.hpp"

using MX = Add_arr<int, 2>;
void Yorisou() {
  INT(N);
  vc<MX::X> dat(N);
  FOR(i, N) {
    INT(x);
    ++dat[i][x & 1];
  }
  seg_t<MX> seg(dat);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      dat[i] = {};
      ++dat[i][x & 1];
      seg.set(i, dat[i]);
    } else {
      INT(l, r);
      --l;
      print(seg.prod(l, r)[op & 1]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}