#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_simple.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  LCT_simple lct(N);
  FOR(Q) {
    STR(op);
    INT(x, y);
    --x, --y;
    if (op[0] == 'Q') {
      Yes(lct.get_rt(x) == lct.get_rt(y));
    } else if (op[0] == 'C') {
      lct.link(x, y);
    } else {
      lct.cut(x, y);
    }
  }
}
#include "YRS/Z_H/main.hpp"