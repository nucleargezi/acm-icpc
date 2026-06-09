#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/trie_low.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  trie_low<18> tr(a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, x);
      --i;
      tr.set(i, x);
    } else if (op == 1) {
      tr.inc();
    } else {
      print(tr.prod());
    }
  }
}

int main() {
  Yorisou();
  return 0;
}