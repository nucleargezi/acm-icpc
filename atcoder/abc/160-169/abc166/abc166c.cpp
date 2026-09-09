#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  int s = 0;
  FOR(n, N) {
    int c = 1;
    for (int x : g[n]) c &= a[x] < a[n];
    s += c;
  }
  print(s);
}

int main() { Yorisou(); }