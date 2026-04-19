#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/coef_of_rationals.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  LL(N, k, sz);
  VEC(mint, f, N);
  VEC(mint, g, N);
  FOR(i, N) g[i] = -g[i];
  g.insert(bg(g), 1);
  f = X.conv(f, g);
  sh(f, N);
  print(X.coef_of_rationals(f, g, k, k + sz));
}

int main() {
  Yorisou();
  return 0;
}