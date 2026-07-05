#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_mono.hpp"
#include "YRS/al/m/max.hpp"

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
  vc<int> to(N - 1), dat(N);
  FOR(i, N - 1) {
    var [a, b, c] = es[i];
    to[i] = v.d[a] < v.d[b] ? b : a;
    dat[to[i]] = c;
  }
  hld_mono<int, Max<int>> seg(v, dat);

  INT(Q);
  FOR(Q) {
    INT(op, a, b);
    if (op == 1) {
      --a;
      seg.set(to[a], b);
    } else {
      --a, --b;
      print(seg.prod(a, b, 1));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}