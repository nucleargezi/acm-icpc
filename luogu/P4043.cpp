#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  INT(N);
  min_cost_bflow<ll, ll> g(N);
  FOR(i, N) {
    INT(sz);
    FOR(k, sz) {
      INT(t, w);
      --t;
      g.add(i, t, 1, inf<int>, w);
    }
  }
  FOR(i, N) g.add(i, 0, 0, inf<int>, 0);
  print(*g.flow());
}

int main() {
  Yorisou();
  return 0;
}