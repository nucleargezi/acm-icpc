#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_assign_pair.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_assign_pair g(a, N + 1);
  uint ls = 0;
  FOR(Q) {
    INT(op, l, r);
    l ^= ls, r ^= ls;
    --l;
    if (op == 1) {
      INT(x);
      x ^= ls;
      g.apply(l, r, x);
    } else {
      ll s = g.prod(l, r);
      print(s);
      ls = s;
    }
  }
}

int main() {
  Yorisou();
  return 0;
}