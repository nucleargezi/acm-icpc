#include "YRS/all.hpp"
#include "YRS/flow/max_flow.hpp"

void yorisou() {
  INT(N, M, s, t);
  max_flow<ll> FL(N, --s, --t);
  FOR(M) {
    INT(x, y, w);
    FL.add(--x, --y, w);
  }
  print(FL.flow());
}