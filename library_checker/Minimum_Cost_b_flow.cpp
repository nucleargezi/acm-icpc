#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  INT(N, M);
  min_cost_bflow<ll, i128> g(N);
  FOR(i, N) {
    LL(b);
    g.add(i, b);
  }
  FOR(i, M) {
    INT(s, t);
    LL(l, r, c);
    g.add(s, t, l, r, c);
  }
  Z s = g.flow();
  if (s) {
    print(*s);
    for (Z x : g.get_pot()) print(x);
    for (Z &&e : g.get_es()) print(e.fl);
  } else {
    print("infeasible");
  }
}

int main() {
  Yorisou();
  return 0;
}