#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/half_ins.hpp"
#include "YRS/ge/basic/area.hpp"

using re = ld;
using P = point<re>;
using H = half_plane<re>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  vc<H> hs;
  FOR(i, N) hs.ep(a[i], a[(i + 1) % N]);
  P e = a[1] - a[0];
  FOR(i, 1, N) {
    P b = a[(i + 1) % N] - a[i], d = b - e;
    re c = b.det(a[i] - a[0]);
    P p = a[0] + d.rol90() * (c / d.sq());
    hs.ep(p, p + d);
  }
  setp(4);
  print(area(half_ins(hs)) / area(a));
}

int main() {
  Yorisou();
  return 0;
}