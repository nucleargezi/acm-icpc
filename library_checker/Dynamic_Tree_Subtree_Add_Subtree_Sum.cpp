#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/toptree/satt.hpp"
#include "YRS/al/am/sum_add.hpp"

using am = a_monoid_sum_add<ll>;
void Yorisou() {
  INT(N, Q);
  satt<am> g(N);
  FOR(i, N) {
    INT(x);
    g.set(i, x);
  }
  FOR(N - 1) {
    INT(x, y);
    g.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y, a, b);
      g.cut(x, y);
      g.link(a, b);
    } else if (op == 1) {
      INT(p, rt, x);
      g.apply_sub(p, rt, x);
    } else {
      INT(x, f);
      print(g.prod_sub(x, f));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}