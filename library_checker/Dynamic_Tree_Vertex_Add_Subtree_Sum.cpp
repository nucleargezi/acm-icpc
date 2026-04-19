// https://icpc.bjtu.edu.cn/problem/11428
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_sub.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  lct_sub<monoid_add<ll>> g(N);
  FOR(i, N) IN(g.a[i].mx);
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
      INT(p, x);
      g.multiply(p, x);
    } else {
      INT(x, f);
      print(g.prod(x, f));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}