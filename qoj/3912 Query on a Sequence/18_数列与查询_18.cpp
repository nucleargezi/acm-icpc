#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/dyn_kdt_mono.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  dyn_kdt_mono<Add<int>, int> seg;
  FOR(i, N) seg.set(i, a[i], 1);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, k);
      --l;
      print(r - l - seg.prod(l, r - 1, 1, k));
    } else {
      INT(i, x);
      --i;
      seg.set(i, a[i], 0);
      seg.set(i, a[i] = x, 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}