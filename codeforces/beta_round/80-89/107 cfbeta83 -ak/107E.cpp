#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/eps.hpp"

using re = ld;
using P = point<re>;
void Yorisou() {
  INT(N);
  vector a(N, vc<P>(4));
  re sm = 0;
  FOR(i, N) {
    re ar = 0;
    FOR(k, 4) {
      INT(x, y);
      a[i][k].x = x, a[i][k].y = y;
    }
    FOR(k, 4) ar += a[i][k].det(a[i][(k + 1) & 3]);
    if (ar < 0) ar = -ar, reverse(a[i]);
    sm += ar / 2;
  }
  print(sm / epbs<ld, 1e-9l>{}.poly_union_ar(a));
}

int main() {
  Yorisou();
  return 0;
}