#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/same_col_tree.hpp"
#include "YRS/al/m/max.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  VEC(int, c, N);
  VEC(int, a, N);
  hld v(g, 0);
  same_col_tree<Max<int>> ds(v, a);
  FOR(i, N) if (c[i]) ds.flip(i);

  INT(Q);
  FOR(Q) {
    INT(op, x);
    --x;
    if (op == 1) {
      ds.flip(x);
    } else if (op == 2) {
      print(ds.prod(x));
    } else {
      INT(w);
      ds.set(x, w);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}