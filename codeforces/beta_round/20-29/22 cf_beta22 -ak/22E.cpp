#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/scc_aug.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(i, N) {
    INT(x);
    --x;
    g[i].ep(x);
  }
  Z s = scc_aug(g);
  print(si(s));
  for (var [a, b] : s) print(a + 1, b + 1);
}

int main() {
  Yorisou();
  return 0;
}