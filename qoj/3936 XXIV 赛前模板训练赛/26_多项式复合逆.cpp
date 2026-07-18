#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps.hpp"
#include "YRS/poly/comp_inv.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(X.comp_inv(f));
}

int main() {
  Yorisou();
  return 0;
}