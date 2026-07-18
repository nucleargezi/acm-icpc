#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/chordal.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b);
    g[b].ep(a);
  }
  chordal ch(g);
  if (ch.build()) {
    Yes();
    print(ch.pe);
  } else {
    NO();
    print(si(ch.cyc));
    print(ch.cyc);
  }
}

int main() {
  Yorisou();
  return 0;
}