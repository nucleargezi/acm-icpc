#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dwave wm(a);
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(l, r, k);
      --l, --k;
      print(wm.kth(l, r, k));
    } else {
      INT(i, x);
      --i;
      wm.set(i, x);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}