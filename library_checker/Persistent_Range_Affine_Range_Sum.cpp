#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/al/am/sum_affine.hpp"
#include "YRS/ds/seg/segdl_t.hpp"

using mint = M99;
using AM = a_monoid_sum_affine<mint>;
using DS = segdl_t<AM, 1>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS seg(0, N);
  vc<np> t(Q + 1);
  VEC(mint, a, N);
  t[0] = seg.newnode(a);
  FOR(i, 1, Q + 1) {
    INT(op, k);
    ++k;
    if (op == 0) {
      INT(l, r, b, c);
      t[i] = seg.apply(t[k], l, r, {b, c});
    } else if (op == 1) {
      INT(s, l, r);
      ++s;
      t[i] = seg.copy(t[k], t[s], l, r);
    } else {
      INT(l, r);
      print(seg.prod(t[i] = t[k], l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}