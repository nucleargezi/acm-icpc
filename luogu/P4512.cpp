#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/poly_divmod.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N + 1);
  VEC(mint, g, M + 1);
  Z [p, q] = poly_divmod(std::move(f), std::move(g));
  print(p);
  print(q);
}

int main() {
  Yorisou();
  return 0;
}