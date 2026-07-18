#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/dlx.hpp"

void Yorisou() {
  INT(N, M);
  dlx g(N, M);
  FOR(i, N) FOR(k, M) {
    INT(x);
    if (x) g.add(i, k);
  }
  if (g.slv()) {
    for (int &x : g.ans) ++x;
    print(g.ans);
  } else {
    print("No Solution!");
  }
}

int main() {
  Yorisou();
  return 0;
}