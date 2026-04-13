#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/un/dynamic_dsu.hpp"

using DS = dynamic_dsu<1, 1 << 18, 2>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS g;
  vc<np> t(Q + 1);
  FOR(i, 1, Q + 1) {
    INT(op);
    if (op == 0) {
      INT(k, x, y);
      ++k;
      t[i] = g.merge(t[k], x, y).fi;
    } else {
      INT(k, x, y);
      ++k;
      t[i] = t[k];
      print(g.same(t[k], x, y));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}