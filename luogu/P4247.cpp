#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/poly_mul_affine.hpp"

using mint = mint_t<19940417>;
using AM = am_poly_mul_affine<mint, 21>;
void Yorisou() {
  INT(N, Q);
  VEC(mint, a, N);
  segl_t<AM> seg(N, [&](int i) { return AM::sing(a[i]); });
  FOR(Q) {
    CH(op);
    if (op == 'I') {
      INT(l, r, x);
      --l;
      seg.apply(l, r, {1, x});
    } else if (op == 'R') {
      INT(l, r);
      --l;
      seg.apply(l, r, {-1, 0});
    } else {
      INT(l, r, c);
      --l;
      print(seg.prod(l, r)[c]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}