#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/spl/splay_set.hpp"

using DS = splay_set<int>;
using np = DS::np;
void Yorisou() {
  INT(Q);
  DS g;
  np t = 0;
  FOR(Q) {
    INT(op, x);
    if (op == 1) g.ins(t, x);
    if (op == 2) g.del(t, x);
    if (op == 3) print(g.rank(t, x) + 1);
    if (op == 4) print(g.kth(t, x - 1));
    if (op == 5) print(g.prev(t, x));
    if (op == 6) print(g.next(t, x));
  }
}

int main() {
  Yorisou();
  return 0;
}