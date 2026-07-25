#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_inv_online.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_inv_online g(a);
  ll ls = 0;
  FOR(Q) {
    LL(l, r);
    l ^= ls, r ^= ls;
    --l;
    print(ls = g.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}