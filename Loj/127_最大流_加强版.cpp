#include "YRS/all.hpp"
#include "YRS/flow/HLPP.hpp"

void yorisou() {
  INT(N, M, s, t);
  --s, --t;
  HLPP FL(N);
  FOR(M) {
    INT(x, y, w);
    FL.add(--x, --y, w);
  }
  print(FL.flow(s, t));
}