#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_sayo.hpp"
#include "YRS/al/am/sum_add.hpp"

using DS = wblt_sayo<Sum_add<ll>>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  constexpr int lm = 1 << 20;
  DS g(lm);
  Z t = g.newnode(a);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      t = g.apply(t, l, r, x);
    } else if (op == 2) {
      INT(l, r, L, R);
      --l, --L;
      t = g.copy(t, l, r, L, R);
    } else {
      INT(l, r);
      --l;
      print(g.prod(t, l, r));
    }
    if (si(g.tr) - g.fr > lm / 2) g.gc(t);
  }
}

int main() {
  INT(T);
  Yorisou();
  return 0;
}