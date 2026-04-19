#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/c/bs.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  ++N, ++M;
  VEC(mint, f, N);
  VEC(mint, g, M);
  print(X.conv(f, g));
}

int main() {
  Yorisou();
  return 0;
}