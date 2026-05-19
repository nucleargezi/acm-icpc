#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/spl/splay_mset.hpp"
#include "YRS/string/run_length.hpp"

using DS = splay_mset<int, int, 20>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  sort(a);
  DS g;
  np t = g.newnode(run_length(a));
  int ls = 0, s = 0;
  FOR(Q) {
    INT(op, x);
    x ^= ls;
    if (op == 1) g.ins(t, x);
    if (op == 2) g.del(t, x);
    if (op == 3) ls = g.rank(t, x) + 1, s ^= ls;
    if (op == 4) ls = g.kth(t, x - 1), s ^= ls;
    if (op == 5) ls = g.prev(t, x), s ^= ls;
    if (op == 6) ls = g.next(t, x), s ^= ls;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}