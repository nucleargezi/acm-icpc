#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_sayo_rev.hpp"
#include "YRS/al/am/sum_affine.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
using DS = wblt_sayo_rev<Sum_affine<mint>>;
void Yorisou() {
  INT(N, Q);
  VEC(mint, a, N);
  constexpr int lm = 1 << 20;
  DS g(lm);
  Z t = g.newnode(a);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      print(g.prod(t, l, r));
    } else if (op == 2) {
      INT(x);
      t = g.apply(t, l, r, {0, x});
    } else if (op == 3) {
      INT(x);
      t = g.apply(t, l, r, {1, x});
    } else if (op == 4) {
      INT(L, R);
      --L;
      t = g.copy(t, L, R, l, r);
    } else if (op == 5) {
      INT(L, R);
      --L;
      if (l > L) swap(l, L), swap(r, R);
      Z [le, cr, rs] = g.spl(t, L, R);
      Z [ls, cl, ms] = g.spl(le, l, r);
      t = g.me(g.me(ls, cr, ms), g.me(cl, rs));
    } else {
      t = g.reverse(t, l, r);
    }
    if (si(g.tr) - g.fr > lm - 1000) g.gc(t);
  }
  print(g.get_all(t));
}

int main() {
  Yorisou();
  return 0;
}