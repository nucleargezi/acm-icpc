#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/max.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  seg_t<Max<int>> seg(a);

  FOR(Q) {
    INT(op, a, b);
    --a;
    if (op == 1) {
      seg.set(a, b);
    } else if (op == 2) {
      print(seg.prod(a, b));
    } else {
      print(seg.maxr([&](int x) { return x < b; }, a) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}