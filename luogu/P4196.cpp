#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/half_ins.hpp"
#include "YRS/ge/basic/area.hpp"

using re = ld;
using P = point<re>;
using H = half_plane<re>;
void Yorisou() {
  INT(N);
  vc<H> a;
  FOR(i, N) {
    INT(n);
    VEC(P, p, n);
    FOR(i, n) a.ep(p[i], p[(i + 1) % n]);
  }
  setp(3);
  print(area(half_ins(a)) / 2);
}

int main() {
  Yorisou();
  return 0;
}