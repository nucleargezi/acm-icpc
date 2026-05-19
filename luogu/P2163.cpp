#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit2.hpp"
#include "YRS/al/m/add.hpp"

using DS = bit2<Add<int>, int>;
void Yorisou() {
  INT(N, Q);
  vc<int> a(N), b(N), w(N, 1);
  FOR(i, N) IN(a[i], b[i]);
  DS bit(a, b, w);
  FOR(Q) {
    INT(l, c, r, d);
    ++r, ++d;
    print(bit.prod(l, r, c, d));
  }
}

int main() {
  Yorisou();
  return 0;
}