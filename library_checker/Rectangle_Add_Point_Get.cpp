#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/dual_bit2.hpp"
#include "YRS/al/m/add.hpp"

using MX = monoid_add<ll>;
using DS = dual_bit2<MX, int, 1>;
void Yorisou() {
  INT(N, Q);
  vc<tuple<int, int, int, int, int>> a(N), q(Q);
  IN(a);
  vc<int> xs, ys;
  FOR(i, Q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d, e);
      q[i] = {a, b, c, d, e};
    } else {
      INT(x, y);
      xs.ep(x), ys.ep(y);
      q[i] = {x, y, -1, -1, -1};
    }
  }
  DS bit(xs, ys);
  for (Z [a, b, c, d, e] : a) bit.apply(a, c, b, d, e);
  for (Z [a, b, c, d, e] : q) {
    if (e == -1) {
      print(bit.get(a, b));
    } else {
      bit.apply(a, c, b, d, e);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}