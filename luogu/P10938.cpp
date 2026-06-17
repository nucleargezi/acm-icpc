#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/max_anti_chain.hpp"

bitset<200> a[200];
void Yorisou() {
  INT(N, M);
  FOR(M) {
    INT(f, t);
    --f, --t;
    a[f][t] = 1;
  }
  FOR(k, N) FOR(i, N) if (a[i][k]) a[i] |= a[k];
  vc<vc<int>> g(N);
  FOR(i, N) FOR(k, N) if (a[i][k]) g[i].ep(k);
  print(si(max_anti_chain(g)));
}


int main() {
  Yorisou();
  return 0;
}