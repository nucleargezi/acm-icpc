#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N, Q);
  dwave g(vc<int>(N, 0));
  FOR(Q) {
    CH(op);
    if (op == 'C') {
      INT(i, x);
      --i;
      g.set(i, x);
    } else {
      INT(l, r);
      --l;
      if (r - l < 8) print(0);
      else print(g.kth(l, r, r - l - 8));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}