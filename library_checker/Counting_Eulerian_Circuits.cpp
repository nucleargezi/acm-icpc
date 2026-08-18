#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/best.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b);
  }
  print(best(g, 998244353));
}

int main() {
  Yorisou();
  return 0;
}