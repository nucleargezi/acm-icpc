#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/flyod.hpp"

void Yorisou() {
  INT(N);
  vector g(N, bs(N));
  FOR(i, N) FOR(k, N) {
    INT(x);
    if (x) g[i].set(k);
  }
  floyd(g);
  FOR(i, N) FOR(k, N) put(g[i][k], " \n"[k + 1 == N]);
}

int main() {
  Yorisou();
  return 0;
}