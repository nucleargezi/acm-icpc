#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/chordal.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }

  chordal v(g);
  if (not v.build()) return No();
  Yes();
  for (int &x : v.pe) ++x;
  print(v.pe);
  print(v.clique, v.cl, v.indsz);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}