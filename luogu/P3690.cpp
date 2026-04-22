#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/al/m/xor.hpp"

void Yorisou() {
  INT(N, Q);
  lct_mono<monoid_xor<int>> g(N);
  FOR(i, N) IN(g[i]->mx);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x, --y;
      print(g.prod(x, y));
    } else if (op == 1) {
      INT(x, y);
      --x, --y;
      if (g.get_rt(x) != g.get_rt(y)) g.link(x, y);
    } else if (op == 2) {
      INT(x, y);
      --x, --y;
      g.evert(x);
      if (g.get_fa(y) == x) g.cut(x, y);
    } else {
      INT(x, y);
      --x;
      g.set(x, y);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}