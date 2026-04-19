#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/un/dsu.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  dsu g(N);
  mint s;
  FOR(Q) {
    INT(op, x, y);
    if (op == 0) g.merge(x, y);
    else s = s * 2 + (g[x] == g[y]);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}