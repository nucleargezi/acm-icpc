#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bct.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  Z ng = bct(g);
  vc<int> s;
  FOR(i, N) if (si(ng[i]) > 1) s.ep(i + 1);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}