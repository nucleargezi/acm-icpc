#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_v.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N << 1);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b + N);
    g[b + N].ep(a);
  }
  BM f(g);
  print(si(f.vcov()));
}

int main() {
  Yorisou();
  return 0;
}