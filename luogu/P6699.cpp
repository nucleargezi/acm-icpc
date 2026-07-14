#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower_w.hpp"

void Yorisou() {
  INT(N, M);
  flower_w g(N);
  FOR(M) {
    INT(a, b, w);
    --a, --b;
    g.add(a, b, w);
  }
  print(g.slv());
  print(vc<int>{bg(g.mt) + 1, bg(g.mt) + N + 1});
}

int main() {
  Yorisou();
  return 0;
}