#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps.hpp"
#include "YRS/poly/multi.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, Q);
  VEC(mint, f, N);
  VEC(mint, x, Q);
  for (Z s : X.eval(f, x)) print(s);
}

int main() {
  Yorisou();
  return 0;
}