#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/range_sumadd.hpp"

void Yorisou() {
  INT(N);
  range_sum_add<ll> g(N);
  FOR(i, N) {
    INT(x);
    g.apply(i, i + 1, x);
  }
  
  FOR(N) {
    INT(op, l, r, x);
    --l;
    if (op == 0) g.apply(l, r, x);
    else print(g.prod(l, r) % (x + 1));
  }
}

int main() {
  Yorisou();
  return 0;
}