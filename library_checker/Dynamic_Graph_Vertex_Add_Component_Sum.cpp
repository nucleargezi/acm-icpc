#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/dynamic_connect.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  dynamic_connect<monoid_add<ll>> g(a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      g.link(x, y);
    } else if (op == 1){
      INT(x, y);
      g.cut(x, y);
    } else if (op == 2) {
      INT(x, y);
      g.multiply(x, y);
    } else if (op == 3) {
      INT(x);
      print(g.component_prod(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}