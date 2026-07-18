#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dmst_fast.hpp"

void Yorisou() {
  INT(N, M, s);
  VEC(T3<int>, es, M);
  Z [rs, fe] = *dmst_fast<ll>(N, s, es);
  vc<int> fa(N, s);
  FOR(i, N) if (i != s) fa[i] = get<0>(es[fe[i]]);
  print(rs);
  print(fa);
}

int main() {
  Yorisou();
  return 0;
}