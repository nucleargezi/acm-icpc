#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_mset.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  sort(a);
  vc<PII> dat;
  for (int x : a) {
    if (dat.empty() or dat.back().fi != x) dat.ep(x, 1);
    else ++dat.back().se;
  }
  avl_mset<int, 0, 1 << 3> g;
  uint t = g.newnode(dat);
  int ls = 0, s = 0;
  FOR(Q) {
    INT(op, x);
    x ^= ls;
    if (op == 1) t = g.ins(t, x);
    if (op == 2) t = g.del(t, x);
    if (op == 3) ls = g.rank(t, x) + 1, s ^= ls;
    if (op == 4) ls = g.kth(t, x - 1), s ^= ls;
    if (op == 5) ls = g.prev(t, x, 0), s ^= ls;
    if (op == 6) ls = g.next(t, x, 0), s ^= ls;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}