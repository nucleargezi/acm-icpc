#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/trie_bina.hpp"

using DS = trie_bina<30>;
void Yorisou() {
  INT(Q);
  DS tr;
  int t = tr.add(0, 0);
  FOR(Q) {
    INT(op, x);
    if (op == 1) t = tr.add(t, x);
    if (op == 2) t = tr.add(t, x, -1);
    if (op == 3) print(tr.max(t, x));
  }
}

int main() {
  Yorisou();
  return 0;
}