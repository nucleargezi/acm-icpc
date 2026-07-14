#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/best.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(n, N) {
    INT(M);
    g[n].resize(M);
    IN(g[n]);
    for (int &x : g[n]) --x;
  }
  print(best(g, 0, 1'000'003));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}