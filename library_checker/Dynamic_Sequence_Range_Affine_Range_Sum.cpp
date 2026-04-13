#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/treap/treap_act.hpp"
#include "YRS/al/am/sum_affine.hpp"

using mint = M99;
using AM = a_monoid_sum_affine<mint>;
using DS = treap_act<AM>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS ds;
  VEC(mint, a, N);
  np t = ds.newnode(a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, x);
      Z [l, r] = ds.spl(t, i);
      t = ds.merge(l, ds.newnode(x), r);
    } else if (op == 1) {
      INT(i);
      Z [l, m, r] = ds.spl(t ,i, i + 1);
      t = ds.merge(l, r);
    } else if (op == 2) {
      INT(l, r);
      t = ds.reverse(t, l, r);
    } else if (op == 3) {
      INT(l, r, b, c);
      t = ds.apply(t, l, r, {b, c});
    } else {
      INT(l, r);
      print(ds.prod(t, l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}