#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/dijkstra.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  graph g(N);
  g.sc<1>(M);
  print(dijkstra<ll>(g, s).fi[t]);
}

int main() {
  Yorisou();
  return 0;
}