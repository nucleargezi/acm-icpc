#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/dynamic_array.hpp"

using DS = dynamic_array<int, 1>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  DS seg(0);
  vc<np> t(Q + 1);
  t[0] = seg.newnode(a);
  FOR(i, 1, Q + 1) {
    INT(v, op);
    if (op == 1) {
      INT(x, w);
      --x;
      t[i] = seg.set(t[v], x, w);
    } else {
      INT(x);
      --x;
      print(seg.get(t[i] = t[v], x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}