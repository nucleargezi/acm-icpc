#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/dist_sum_apply.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g);
  dist_sum_apply<int, ll> ds(v);
  
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b);
      --a, --b;
      ds.apply_sub(b, a, 1);
    } else if (op == 2) {
      INT(a, b);
      --a, --b;
      ds.apply(a, b, 1);
    } else {
      INT(x);
      --x;
      print(ds.prod(x));
    }
  }
}

int main() { Yorisou(); }