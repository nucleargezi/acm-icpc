#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/sp_mcf.hpp"

void Yorisou() {
  INT(N, M);
  retsu<int> c(N, M);
  IN(c);
  VEC(int, sp, M);
  sp_mcf<ll> g(M, N, sp);
  FOR(i, N) FOR(k, M) g.add(k, i, c[i][k]);
  print(g.flow()[N]);
}

int main() {
  Yorisou();
  return 0;
}