#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_abel.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q, t);
  --t;
  VEC(ll, a, N);
  graph g(N);
  g.sc();
  hld v(g, t);
  hld_abel<int, monoid_add<ll>, 0, 0, 1> seg(v, a);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      seg.multiply(i, x);
    } else {
      INT(i);
      --i;
      print(seg.prod_sub(i));
    }  
  }
}

int main() {
  Yorisou();
  return 0;
}