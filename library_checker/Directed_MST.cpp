#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dmst_fast.hpp"

void Yorisou() {
  INT(N, M, s);
  VEC(T3<int>, e, M);
  Z [w, fe] = *dmst_fast<ll>(N, s, e);
  vc<int> fa(N, s);
  FOR(i, N) if (i != s) fa[i] = get<0>(e[fe[i]]);
  print(w);
  print(fa);
}

int main() {
  Yorisou();
  return 0;
}