#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/lct/lct_base.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  LCT_base lct(N + 1);
  FOR(i, N) a[i] = min(i + a[i], N), lct.link(i, a[i]);
  INT(Q);
  FOR(Q) {
    INT(op, i);
    if (op == 1) {
      print(lct.dist(i, N));
    } else {
      INT(k);
      k = min(i + k, N);
      lct.cut(i, a[i]);
      lct.link(i, a[i] = k);
    }
  }
}
#include "YRS/Z_H/main.hpp"