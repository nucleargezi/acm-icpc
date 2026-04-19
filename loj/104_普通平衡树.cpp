#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/treap/treap_base.hpp"

using DS = treap_base<int>;
using np = DS::np;
void Yorisou() {
  INT(Q);
  DS g;
  np t = 0;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x);
      Z [l, r] = g.split_max_right(t, [&](int t) { return t < x; });
      t = g.merge(l, g.newnode(x), r);
    } else if (op == 2) {
      INT(x);
      Z [l, rs] = g.split_max_right(t, [&](int t) { return t < x; });
      Z [m, r] = g.spl(rs, 1);
      t = g.merge(l, r);
    } else if (op == 3) {
      INT(x);
      Z [l, r] = g.split_max_right(t, [&](int t) { return t < x; });
      print(l ? l->sz + 1 : 1);
      t = g.merge(l, r);
    } else if (op == 4) {
      INT(x);
      print(g.get(t, x - 1));
    } else if (op == 5) {
      INT(x);
      Z [ls, r] = g.split_max_right(t, [&](int t) { return t < x; });
      Z [l, m] = g.spl(ls, ls->sz - 1);
      print(m->mx);
      t = g.merge(l, m, r);
    } else {
      INT(x);
      Z [l, rs] = g.split_max_right(t, [&](int t) { return t <= x; });
      Z [m, r] = g.spl(rs, 1);
      print(m->mx);
      t = g.merge(l, m, r);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}