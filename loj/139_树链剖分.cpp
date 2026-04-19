#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_laz.hpp"
#include "YRS/al/am/sum_add.hpp"

void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g.add(f, i);
  }
  g.build();
  hld v(g);
  hld_mono_laz<int, a_monoid_sum_add<ll>> seg(v, a);
  
  int t = 0;
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      IN(t);
      --t;
    } else if (op == 2) {
      INT(x, y, c);
      --x, --y;
      seg.apply(x, y, c);
    } else if (op == 3) {
      INT(i, x);
      --i;
      seg.apply_sub_rt(i, t, x);
    } else if (op == 4) {
      INT(x, y);
      --x, --y;
      print(seg.prod(x, y));
    } else {
      INT(i);
      --i;
      print(seg.prod_sub(i, t));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}