#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_mono.hpp"
#include "YRS/al/m/add.hpp"

using MX = monoid_add<ll>;
using DS = hld_mono<int, MX, 0>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  graph g(N);
  g.sc<0, 0>();
  hld v(g);
  DS seg(v, a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, x);
      seg.multiply(i, x);
    } else {
      INT(x, y);
      print(seg.prod(x, y));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}