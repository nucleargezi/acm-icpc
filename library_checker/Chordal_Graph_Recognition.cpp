#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/chordal.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b), g[b].ep(a);
  }

  chordal v(g);
  if (not v.build()) return NO(), print(si(v.cyc)), print(v.cyc);
  YES(), print(v.pe);
}

int main() {
  Yorisou();
  return 0;
}