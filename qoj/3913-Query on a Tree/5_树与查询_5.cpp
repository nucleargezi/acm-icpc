#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tree_flip_nearest.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  tree_flip_nearest ds(g);

  INT(Q);
  FOR(Q) {
    INT(op, x);
    --x;
    if (op == 1) ds.flip(x);
    else print(ds.prod(x));
  }
}

int main() {
  Yorisou();
  return 0;
}