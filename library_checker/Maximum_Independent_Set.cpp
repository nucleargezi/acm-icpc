#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/max_independent_set.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  vc<int> s = max_independent_set(g);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}