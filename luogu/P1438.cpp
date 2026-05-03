#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/al/m/add_line.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  seg_dual_t<monoid_add_line<ll>> seg(N);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      LL(l, r, k, d);
      --l;
      seg.apply(l, r, {k - l * d, d});
    } else {
      INT(i);
      --i;
      Z [h, k] = seg.get(i);
      print(a[i] + k * i + h);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}