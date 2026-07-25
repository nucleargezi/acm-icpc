#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/angelbeats.hpp"
#include "YRS/al/beats/ktt_max_subarray_sum.hpp"

using beats = Kttmax_subarr_sum<ll>;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  AngelBeats<beats> seg(N, [&](int i) { return beats::sing(a[i]); });
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      seg.apply(l, r, x);
    } else {
      INT(l, r);
      --l;
      print(max(0ll, seg.prod(l, r).mx));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}