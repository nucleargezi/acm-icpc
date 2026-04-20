#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/HLPP.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  HLPP<ll, 1200> g(N);
  FOR(M) {
    INT(f, t, w);
    --f, --t;
    g.add(f, t, w);
  }
  g.build();
  print(g.flow(s, t));
}

int main() {
  Yorisou();
  return 0;
}