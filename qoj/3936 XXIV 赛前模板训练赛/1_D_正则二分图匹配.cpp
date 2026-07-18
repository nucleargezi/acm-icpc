#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/regular_bm.hpp"

void Yorisou() {
  INT(N, d);
  vc<vc<int>> g(N, vc<int>(d));
  IN(g);
  FOR(i, N) FOR(k, d) --g[i][k];
  Z s = regular_bm(g);
  for (int &x : s) ++x;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}