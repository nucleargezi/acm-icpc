#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/sort_seg.hpp"

struct MX {
  struct X {};
  static X op(X, X) { return {}; }
  static X unit() { return {}; }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  sort_seg<MX> seg(a, vc<MX::X>(N));
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 0) seg.sort_inc(l, r);
    else seg.sort_dec(l, r);
  }
  INT(x);
  print(seg.get_ke(x - 1));
}

int main() {
  Yorisou();
  return 0;
}