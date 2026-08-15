#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/poly_gcd.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N + 1);
  VEC(mint, g, N);
  Z [d, a, b] = poly_edgcd(f, g);
  Z in = d[0].inv();
  for (Z &x : b) x *= in;
  sh(b, N);
  print(b);
}

int main() {
  Yorisou();
  return 0;
}