#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/g/enumerate_clique.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  graph g(N);
  g.sc<0, 0>(M);
  mint s;
  enumerate_cliques(g, [&](var v) {
    mint t = 1;
    for (int x : v) t *= a[x];
    s += t;
  });
  print(s);
}

int main() {
  Yorisou();
  return 0;
}