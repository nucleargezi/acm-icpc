#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_base.hpp"

void Yorisou() {
  INT(Q);
  using DS = avl_base<char, 1>;
  using np = DS::np;
  DS g;
  vc<np> t(Q + 1);
  int k = 0;
  FOR(Q) {
    CH(op);
    if (op == 'T') {
      CH(c);
      t[k + 1] = g.me(t[k], g.newnode(c));
      ++k;
    } else if (op == 'U') {
      INT(x);
      t[k + 1] = t[k - x];
      ++k;
    } else {
      INT(x);
      --x;
      print(g.get(t[k], x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}