#include "YRS/all.hpp"
#include "YRS/flow/mcf.hpp"

void yorisou() {
  INT(N, M);
  mcf FL(N);
  FOR(M) {
    INT(x, y, c, w);
    FL.add(--x, --y, c, w);
  }
  print(FL.flow(0, N - 1));
}