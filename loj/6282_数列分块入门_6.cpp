#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/treap/treap_base.hpp"

using DS = treap_base<int>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  DS g;
  np t = g.newnode(a);
  
  FOR(N) {
    INT(op, l, r, x);
    --l;
    if (op == 0) {
      Z [a, b] = g.spl(t, l);
      t = g.merge(a, g.newnode(r), b);
    } else {
      print(g.get(t, r - 1));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}