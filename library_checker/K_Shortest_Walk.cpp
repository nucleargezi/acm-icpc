#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/k_shortest/k_short_walk.hpp"

void Yorisou() {
  INT(N, M, s, t, k);
  graph<ll, 1> g(N);
  g.sc<1, 0>(M);
  for (ll x : k_short_walk(g, s, t, k)) print(x == inf<ll> ? -1 : x);
}

int main() {
  Yorisou();
  return 0;
}