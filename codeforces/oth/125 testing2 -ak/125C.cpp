#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  int sz = 1;
  while (sz * (sz + 1) / 2 <= N) ++sz;
  int t = 1;
  vc<vc<int>> g(sz);
  FOR(i, sz) FOR(k, i) g[i].ep(t), g[k].ep(t), ++t;
  print(sz);
  FOR(i, sz) print(g[i]);
}

int main() {
  Yorisou();
  return 0;
}