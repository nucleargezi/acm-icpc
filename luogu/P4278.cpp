#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  dwave<17> wm(std::move(a));
  INT(Q);
  int ls = 0;
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(l, r, k);
      l ^= ls, r ^= ls, k ^= ls;
      --l, --k;
      print(ls = wm.kth(l, r, k));
    } else if (op == 'M') {
      INT(i, x);
      i ^= ls, x ^= ls;
      --i;
      wm.set(i, x);
    } else {
      INT(i, x);
      i ^= ls, x ^= ls;
      --i;
      wm.ins(i, x);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}