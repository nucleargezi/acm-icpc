#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/steiner.hpp"

void Yorisou() {
  INT(N, M);
  graph<ll> g(N);
  g.sc<1, 0>(M);
  INT(sz);
  VEC(int, s, sz);
  Z [cost, vs, es] = steiner_tree(g, s);
  print(cost, si(es));
  print(es);
}

int main() {
  Yorisou();
  return 0;
}