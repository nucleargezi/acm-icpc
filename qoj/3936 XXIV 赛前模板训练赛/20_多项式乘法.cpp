#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N + 1);
  VEC(mint, g, M + 1);
  print(X.conv(f, g));
}

int main() {
  Yorisou();
  return 0;
}