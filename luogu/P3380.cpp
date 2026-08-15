#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dwave wm(a);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      print(wm.rank(l, r, x) + 1);
    } else if (op == 2) {
      INT(l, r, k);
      --l, --k;
      print(wm.kth(l, r, k));
    } else if (op == 3) {
      INT(i, x);
      --i;
      wm.set(i, x);
    } else if (op == 4) {
      INT(l, r, x);
      --l;
      print(max(-inf<int>, wm.prev(l, r, x)));
    } else {
      INT(l, r, x);
      --l;
      print(wm.next(l, r, x + 1));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}