#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  dsu g(N);
  int f = 0;
  FOR(M) {
    INT(a, b);
    --a, --b;
    f += not g.merge(a, b);
  }
  print((f == 1 and g.c == 1) ? "FHTAGN!" : "NO");
}

int main() {
  Yorisou();
  return 0;
}