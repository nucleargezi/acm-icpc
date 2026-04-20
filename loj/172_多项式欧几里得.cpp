#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/poly_gcd.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  VEC(mint, f, N + 1);
  VEC(mint, g, N);
  while (si(g) and g.back().val() == 0) pop(g);
  Z [d, a, b] = X.poly_exgcd(f, g);
  mint in = d[0].inv();
  for (mint &x : b) x *= in;
  sh(b, N);
  print(b);
}

int main() {
  Yorisou();
  return 0;
}