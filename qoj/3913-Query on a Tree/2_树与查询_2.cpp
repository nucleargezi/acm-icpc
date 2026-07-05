#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_mono.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  vc<T3<int>> es(N - 1);
  FOR(i, N - 1) {
    INT(a, b, c);
    --a, --b;
    es[i] = {a, b, c};
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g, 0);
  vc<int> dat(N);
  FOR(i, N - 1) {
    var [a, b, c] = es[i];
    dat[v.d[a] < v.d[b] ? b : a] = c;
  }
  hld_mono<int, Add<ll>> seg(v, {all(dat)});

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b);
      --a, --b;
      print(seg.prod(a, b, 1));
    } else {
      INT(a, b, k);
      --a, --b, --k;
      print(v.jump(a, b, k) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}