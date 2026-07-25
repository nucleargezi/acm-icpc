#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_mode_online.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_mode_online g(a);
  int ls = 0;
  FOR(Q) {
    INT(l, r);
    l ^= ls, r ^= ls;
    --l;
    print(ls = g.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}