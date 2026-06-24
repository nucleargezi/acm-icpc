#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, Q);
  dsu g(N);
  FOR(Q) {
    INT(op, a, b);
    if (op == 0) g.merge(a, b);
    else print(g[a] == g[b]);
  }
}

int main() {
  Yorisou();
  return 0;
}