#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_v.hpp"

void Yorisou() {
  INT(L, R, M);
  vc<vc<int>> g(L + R);
  FOR(M) {
    INT(a, b);
    a -= 1, b -= 1 - L;
    g[a].ep(b), g[b].ep(a);
  }
  Z mat = BM_v(g)();
  print(si(mat));
  for (var [a, b] : mat) print(a + 1, b + 1 - L);
}

int main() {
  Yorisou();
  return 0;
}