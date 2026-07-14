#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/dyn_kdt_mono.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dyn_kdt_mono<Add<int>, int> ds(N + Q);
  FOR(i, N) {
    int x = i, y = a[i];
    tie(x, y) = pair(x + y, x - y);
    ds.add(x, y, 1);
  }
  FOR(Q) {
    STR(op);
    if (op[0] == 'M') {
      INT(i, k);
      --i;
      int x, y;
      x = i, y = a[i] = k;
      tie(x, y) = pair(x + y, x - y);
      ds.add(x, y, 1);
    } else {
      INT(i, d);
      --i;
      int x = i, y = a[i];
      tie(x, y) = pair(x + y, x - y);
      print(ds.prod(x - d, x + d, y - d, y + d));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}