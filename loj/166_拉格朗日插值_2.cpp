#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/poly/lag.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  ++N;
  VEC(mint, f, N);
  print(X.lag(f, M, N));
}

int main() {
  Yorisou();
  return 0;
}