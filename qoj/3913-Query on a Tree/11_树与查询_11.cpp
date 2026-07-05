#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_simple.hpp"

void Yorisou() {
  INT(N, Q);
  lct_simple ds(N);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b);
      --a, --b;
      ds.link(a, b);
    } else if (op == 2) {
      INT(a);
      --a;
      ds.cut_fa(a);
    } else {
      INT(a, b);
      --a, --b;
      print(ds.lca(a, b) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}