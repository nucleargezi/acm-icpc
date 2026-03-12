#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N, Q);
  bs a(N), b(N);
  ll sa = 0, sb = 0;
  FOR(Q) {
    INT(op, l, r);
    ++r;
    if (op == 0) {
      int sca = a.range_count(l, r), scb = b.range_count(l, r);
      if (sca > scb) sa += sca;
      if (sca < scb) sb += scb;
    } else if (op == 1) {
      a.range_set(l, r);
      b.range_reset(l, r);
    } else {
      a.range_reset(l, r);
      b.range_set(l, r);
    }
  }
  print(sa + a.count(), sb + b.count());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"