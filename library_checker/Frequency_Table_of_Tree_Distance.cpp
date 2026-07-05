#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tree_all_dist.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    g[a].ep(b), g[b].ep(a);
  }
  print(tree_all_dist(g));
}

int main() {
  Yorisou();
  return 0;
}