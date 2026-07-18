#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/mcf.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  mcf<int, int> g(N);
  FOR(M) {
    INT(f, t, c, w);
    --f, --t;
    g.add(f, t, c, w);
  }
  print(g.flow(s, t));
}

int main() {
  Yorisou();
  return 0;
}