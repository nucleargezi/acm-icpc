#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M);
  flow_lm<ll> g(N, 0, 0);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  if (g.check().fi) {
    Yes();
    for (var [a, b, c] : g.get_flow_es()) print(c);
  } else {
    No();
  }
}

int main() {
  Yorisou();
  return 0;
}