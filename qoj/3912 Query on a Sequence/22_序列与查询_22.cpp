#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd.hpp"
#include "YRS/al/m/add.hpp"

using DS = segd<Add<ll>, 1>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(int, a ,N);
  INT(Q);
  DS seg(0, N);
  vc<np> t(Q + 1);
  FOR(i, N) t[0] = seg.set(t[0], i, a[i]);
  int c = 0;
  FOR(i, Q) {
    INT(op);
    if (op == 1) {
      INT(x, w);
      --x;
      t[c + 1] = seg.set(t[c], x, w);
      ++c;
    } else {
      INT(k, l, r);
      --l;
      print(seg.prod(t[k], l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}