#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/al/am/sum_affine.hpp"
#include "YRS/ds/kdt/dyn_kdt_sayo.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  dyn_kdt_sayo<2, Sum_affine<mint>, int> seg(N + Q);
  FOR(i, N) {
    INT(x, y, w);
    seg.ins({x, y}, w);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y, w);
      seg.ins({x, y}, mint(w));
    } else if (op == 1) {
      INT(i, w);
      seg.set(i, w);
    } else {
      INT(l, c, r, d);
      --r, --d;
      if (op == 2) {
        print(seg.prod({l, c}, {r, d}));
      } else {
        INT(a, b);
        seg.apply({l, c}, {r, d}, {a, b});
      }
    }
  }
}

int main() {
  Yorisou();
  return 0;
}