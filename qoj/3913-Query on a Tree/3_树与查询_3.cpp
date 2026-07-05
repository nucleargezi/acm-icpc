#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_mono.hpp"
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
  hld_mono<int, Add<int>> seg(v);
  vc<char> a(N);

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x);
      --x;
      a[x] ^= 1;
      seg.set(x, a[x]);
    } else {
      INT(x);
      --x;
      int y = seg.maxr([&](int s) { return s == 0; }, 0, x);
      if (y == -1) {
        print(1);
      } else {
        if (y == x) print(-1);
        else print(v.jump(y, x, 1) + 1);
      }
    }
  }
}

int main() {
  Yorisou();
  return 0;
}