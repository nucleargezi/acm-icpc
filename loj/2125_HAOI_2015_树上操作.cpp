#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_laz.hpp"
#include "YRS/al/am/sum_add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  graph g(N);
  g.sc();
  hld v(g);
  hld_mono_laz<int, a_monoid_sum_add<ll>> seg(v, a);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.apply(i, x);
    } else if (op == 2) {
      INT(i, x);
      --i;
      seg.apply_sub(i, x);
    } else {
      INT(i);
      --i;
      print(seg.prod(0, i));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}