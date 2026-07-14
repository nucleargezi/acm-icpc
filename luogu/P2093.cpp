#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/kdt.hpp"

void Yorisou() {
  INT(N);
  vc<tuple<int, int, int>> dat(N);
  FOR(i, N) {
    Z &[ x, y, id ] = dat[i];
    IN(x, y);
    id = i;
  }
  kdt ds(all(dat));

  INT(Q);
  FOR(Q) {
    INT(x, y, k);
    --k;
    print(ds.kth_far(x, y, k) + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}