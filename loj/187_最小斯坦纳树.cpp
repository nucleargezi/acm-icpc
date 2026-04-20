#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/steiner.hpp"

void Yorisou() {
  INT(N, M, K);
  graph g(N);
  g.sc<1>(M);
  VEC(int, a, K);
  for (int &x : a) --x;
  print(get<0>(steiner_tree(g, a)));
}

int main() {
  Yorisou();
  return 0;
}