#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/sort_seg_xor.hpp"
#include "YRS/al/m/xor.hpp"

struct MX : Xor<uint> {
  static X key_map(X a, uint x, ll n) { return a ^ (n & 1 ? x : 0); }
};

void Yorisou() {
  INT(N, Q);
  VEC(uint, a ,N);
  sort_seg_xor<MX> seg(a, a);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, x);
    } else if (op == 2) {
      seg.sort_inc(l, r);
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}