#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/same_col_tree.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g, 0);
  same_col_tree<Add<int>> ds(v, vc<int>(N, 1));

  INT(Q);
  FOR(Q) {
    INT(op, x);
    --x;
    if (op == 1) {
      ds.flip(x);
    } else {
      print(ds.prod(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}