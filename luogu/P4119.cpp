#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_replace_kth.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_replace_kth g(a, 1'000'01);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x, y);
      g.apply(l, r, x, y);
    } else {
      INT(k);
      --k;
      print(g.kth(l, r, k));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}