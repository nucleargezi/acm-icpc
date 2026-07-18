#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/mcf.hpp"

void Yorisou() {
  INT(N, M);
  mcf g(N);
  FOR(M) {
    INT(f, t, w, c);
    --f, --t;
    g.add(f, t, w, c);
  }
  print(g.flow(0, N - 1));
}

int main() {
  Yorisou();
  return 0;
}