#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_wm.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  hld v(g, 0);
  hld_wm<int> wm(v, a);

  INT(Q);
  FOR(Q) {
    INT(a, b, k);
    --a, --b, --k;
    print(wm.kth(a, b, k));
  }
}

int main() {
  Yorisou();
  return 0;
}