#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"
#include "YRS/ds/bit/range_sumadd.hpp"

void Yorisou() {
  INT(N, Q, t);
  --t;
  VEC(ll, a, N);
  graph g(N);
  g.sc();
  hld v(g, t);
  range_sum_add<ll> seg(N);
  FOR(i, N) seg.apply(v.L[i], v.L[i] + 1, a[i]);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      i = v.L[i];
      seg.apply(i, i + 1, x);
    } else if (op == 2) {
      INT(i, x);
      --i;
      seg.apply(v.L[i], v.R[i], x);
    } else {
      INT(a, b);
      --a, --b;
      ll s = 0;
      for (Z [l, r] : v.dec(a, b, 0)) {
        if (l > r) swap(l, r);
        s += seg.prod(l, r + 1);
      }
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}