#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/sswave.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  sswave g(a);
  FOR(Q) {
    INT(l, r);
    --l;
    int x = g.median(l, r);
    print(g.count(l, r, x, x + 1) * 2 > r - l ? x : 0);
  }
}

int main() {
  Yorisou();
  return 0;
}