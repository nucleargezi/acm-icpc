#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_sub.hpp"
#include "YRS/al/m/add.hpp"

using LCT = lct_sub<monoid_add<int>>;
void Yorisou() {
  INT(N, Q);
  LCT lct(N);
  FOR(i, N) lct.a[i].mx = 1;
  FOR(Q) {
    CH(op);
    INT(x, y);
    --x, --y;
    if (op == 'A') lct.link(x, y);
    else print(1ll * lct.prod(x, y) * lct.prod(y, x));
  }
}

int main() {
  Yorisou();
  return 0;
}