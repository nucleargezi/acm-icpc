#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/scc.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b);
  }
  Z [c, id] = scc(g);
  vc<vc<int>> s(c);
  FOR(i, N) s[id[i]].ep(i);
  print(si(s));
  for (var s : s) print(si(s), s);
}

int main() {
  Yorisou();
  return 0;
}