#include "YRS/all.hpp"
#include "YRS/ds/lct/LCT_act.hpp"
#include "YRS/ds/lct/node_acted.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"

// #define tests
using mono = a_monoid_sum_add<int>;
using DS = LCT_act<lct_node_acted<mono>>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS lct(N + N - 1);
  vector<PII> go;
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, N + i);
    lct.link(y, N + i);
  }
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(x, y);
      --x, --y;
      Yes(lct.prod_path(x, y) == 0);
    } else if (op == 'C') {
      INT(x, y);
      --x, --y;
      x = lct.jump(x, y, 1);
      y = lct.jump(y, x, 1);
      go.ep(x, y);
      lct.apply_path(x, y, 1);
    } else {
      INT(x);
      --x;
      lct.apply_path(go[x].fi, go[x].se, -1);
    }
  }
}
#include "YRS/Z_H/main.hpp"