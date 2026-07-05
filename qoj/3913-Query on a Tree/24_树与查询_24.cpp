#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/dec_lca.hpp"

void Yorisou() {
  INT(N, Q);
  dec_lca ds(N);
  FOR(Q) {
    INT(op, a, b);
    if (op == 1) {
      --a;
      ds.upd(a, b);
    } else {
      --a, --b;
      print(ds.lca(a, b) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}