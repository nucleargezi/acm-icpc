#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  vc<int> q;
  FOR(i, N) {
    INT(f);
    if (f == -1) q.ep(i);
    else g[f - 1].ep(i);
  }
  vc<int> d(N, 1);
  while (si(q)) {
    int n = pop(q);
    for (int x : g[n]) d[x] = d[n] + 1, q.ep(x);
  }
  print(QMAX(d));
}

int main() {
  Yorisou();
  return 0;
}