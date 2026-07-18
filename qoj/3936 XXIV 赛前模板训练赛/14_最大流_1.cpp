#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  max_flow<ll> g(N, s, t);
  FOR(M) {
    INT(f, t, w);
    --f, --t;
    g.add(f, t, w);
  }
  print(g.flow());
}

int main() {
  Yorisou();
  return 0;
}