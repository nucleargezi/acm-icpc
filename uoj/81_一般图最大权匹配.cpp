#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower_w.hpp"

void Yorisou() {
  INT(N, M);
  flower_w g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g.add(a, b, c);
  }
  print(g.slv());
  Z mat = move(g.ma);
  print(vc<int>{bg(mat) + 1, bg(mat) + 1 + N});
}

int main() { Yorisou(); }