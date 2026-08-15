#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_sub_sayo.hpp"
#include "YRS/al/am/sum_add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  lct_sub_sayo<Sum_add<ll>> g({all(a)});
  FOR(N - 1) {
    INT(a, b);
    g.link(a, b);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d);
      g.cut(a, b), g.link(c, d);
    } else if (op == 1) {
      INT(n, p, x);
      g.apply(n, p, x);
    } else {
      INT(n, p);
      print(g.prod(n, p));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}