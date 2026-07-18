#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/tr_ecc.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b), g[b].ep(a);
  }
  Z [c, id] = trecc(g);
  print(c);
  vc<vc<int>> s(N);
  FOR(i, N) s[id[i]].ep(i);
  FOR(i, N) if (si(s[i])) print(si(s[i]), s[i]);
}

int main() {
  Yorisou();
  return 0;
}