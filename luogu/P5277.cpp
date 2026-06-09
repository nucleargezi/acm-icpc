#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps_sqrt.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  print(X.sqrt(f));
}

int main() {
  Yorisou();
  return 0;
}