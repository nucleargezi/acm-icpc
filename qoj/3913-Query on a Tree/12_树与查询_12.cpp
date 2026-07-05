#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_simple.hpp"

void Yorisou() {
  INT(N, Q);
  lct_simple ds(N);
  FOR(Q) {
    INT(op, a, b);
    --a, --b;
    if (op == 1) {
      ds.link(a, b);
    } else if (op == 2) {
      ds.cut(a, b);
    } else {
      print(ds.get_rt(a) == ds.get_rt(b));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}