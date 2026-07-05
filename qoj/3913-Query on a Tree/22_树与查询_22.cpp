#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/lex_toptree.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld<int> v(g, 0);
  vc<int> a(N);
  iota(all(a), 0);
  lex_toptree dp(v, a);

  int ls = 0;
  INT(Q);
  FOR(Q) {
    INT(x, y);
    x = (x - 1 + ls) % N, y = (y - 1 + ls) % N;
    swap(a[x], a[y]);
    dp.set(x, a[x]), dp.set(y, a[y]);
    print(ls = dp.prod(x) + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}