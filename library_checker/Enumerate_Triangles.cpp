#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/g/enumerate_c3.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N);
  graph g(N);
  g.sc<0, 0>(M);
  mint s;
  enumerate_c3(g, [&](int i, int k, int j) { s += a[i] * a[k] * a[j]; });
  print(s);
}

int main() {
  Yorisou();
  return 0;
}