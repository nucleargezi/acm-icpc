#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/coef_of_rationals.hpp"

using mint = M99;
void Yorisou() {
  INT(K, N);
  VEC(mint, g, N);
  VEC(mint, f, N);
  FOR(i, N) g[i] = -g[i];
  g.insert(bg(g), 1);
  f = f * g;
  sh(f, N);
  print(coef_of_rationals(f, g, K));
}

int main() {
  Yorisou();
  return 0;
}