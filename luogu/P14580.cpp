#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  flow_lm<ll> g(N, s, t);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  Z [ok, res] = g.qmin();
  if (not ok) print('N');
  else print(res);
}

int main() {
  Yorisou();
  return 0;
}