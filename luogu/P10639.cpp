#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/beats_sum_minmax_chminmax.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  beats_sum_minmax_chminmax<ll> seg(a);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      seg.add(l, r, x);
    } else if (op == 2) {
      INT(l, r, x);
      --l;
      seg.chmax(l, r, x);
    } else if (op == 3) {
      INT(l, r, x);
      --l;
      seg.chmin(l, r, x);
    } else {
      INT(l, r);
      --l;
      Z [s, mn, mx] = seg.prod(l, r);
      print(op == 4 ? s : op == 5 ? mx : mn);
    }
  }
}
#include "YRS/Z_H/main.hpp"