#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/max_flow.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  VEC(T4<int>, es, M);
  max_flow<ll> mx(N, s, t);
  for (Z &[a, b, c, w] : es) {
    --a, --b;
    mx.add(a, b, c);
  }
  ll f = mx.flow();
  min_cost_bflow<ll, ll> g(N);
  for (var [a, b, c, w] : es) g.add(a, b, 0, c, w);
  g.add(s, f), g.add(t, -f);
  print(f, *g.flow());
}

int main() { Yorisou(); }