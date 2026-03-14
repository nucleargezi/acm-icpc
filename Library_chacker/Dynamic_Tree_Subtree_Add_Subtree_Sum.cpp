#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/toptree/satt.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  SATT<a_monoid_sum_add<ll>> satt(N);
  FOR(i, N) {
    INT(x);
    satt.set(i, x);
  }
  FOR(N - 1) {
    INT(x, y);
    satt.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y, a, b);
      satt.cut(x, y);
      satt.link(a, b);
    } else if (op == 1) {
      INT(p, rt, x);
      satt.apply_sub(p, rt, x);
    } else {
      INT(x, f);
      print(satt.prod_sub(x, f));
    }
  }
}
#include "YRS/Z_H/main.hpp"