#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tr_rand_walk_nbt.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N, s, t);
  --s, --t;
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
    g[i].ep(f);
  }
  if (s == t) print(0);
  else print(SUM<mint>(tr_rand_walk_nbt<mint>(g, s, t)) - 1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}