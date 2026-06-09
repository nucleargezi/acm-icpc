#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ttr/tr_rand_walk.hpp"

using mint = M99;
void Yorisou() {
  INT(N, s, t);
  --s, --t;
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  print(tr_rand_walk<mint>(g, s, t));
}

int main() {
  Yorisou();
  return 0;
}