#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/dominator_tree.hpp"

void Yorisou() {
  INT(N, M, t);
  graph<int, 1> g(N);
  g.sc<0, 0>(M);
  vc<int> fa = dominator(g, t);
  fa[t] = t;
  print(fa);
}

int main() {
  Yorisou();
  return 0;
}