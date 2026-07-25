#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_div_sum.hpp"

void Yorisou() {
  INT(N ,Q);
  VEC(int, a, N);
  range_div_sum g(a);
  ll ls = 0;
  FOR(Q) {
    INT(op, l, r);
    l ^= ls, r ^= ls;
    --l;
    if (op == 1) {
      INT(x);
      x ^= ls;
      g.apply(l, r, x);
    } else {
      print(ls = g.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}