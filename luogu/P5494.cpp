#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd_t.hpp"
#include "YRS/al/m/add.hpp"

using DS = segd_t<Add<ll>>;
using np = DS::np;
void Yorisou() {
  INT(N, M);
  DS seg(1, N + 1);
  vc<np> rt(M + 2);
  FOR(i, 1, N + 1) {
    LL(a);
    if (a) rt[1] = seg.set(rt[1], i, a);
  }
  int c = 1;
  FOR(M) {
    INT(op, p);
    if (op == 0) {
      INT(x, y);
      rt[++c] = seg.split(rt[p], x, y + 1);
    } else if (op == 1) {
      int t;
      IN(t);
      rt[p] = seg.merge(rt[p], rt[t]);
      rt[t] = 0;
    } else if (op == 2) {
      LL(x);
      INT(q);
      rt[p] = seg.add(rt[p], q, x);
    } else if (op == 3) {
      INT(x, y);
      print(seg.prod(rt[p], x, y + 1));
    } else {
      LL(k);
      int a = seg.maxr(rt[p], [&](ll b) { return b < k; }, 1);
      print(a == N + 1 ? -1 : a);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}