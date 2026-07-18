#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  using T = tuple<int, int, int, int, int>;
  VEC(T, es, M);
  for (Z &[f, t, l, r, c] : es) --f, --t;
  min_cost_bflow<ll, ll> g(N);
  for (var [f, t, l, r, c] : es) g.add(f, t, l, r, 0);
  g.add(t, s, 0, inf<int>, -1);
  Z fl = g.flow();
  if (not fl) return print(-1);
  g = min_cost_bflow<ll, ll>(N);
  for (var [f, t, l, r, c] : es) g.add(f, t, l, r, c);
  g.add(t, s, -*fl, -*fl, 0);
  print(-*fl, *g.flow());
}

int main() {
  Yorisou();
  return 0;
}