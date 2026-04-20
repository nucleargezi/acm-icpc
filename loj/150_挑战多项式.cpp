#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps.hpp"
#include "YRS/poly/fps_sqrt.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, K);
  ++N;
  VEC(mint, f, N);
  fps g = X.exp(X.inte(X.inv(X.sqrt(f))));
  f[0] = 2;
  sh(g, N);
  FOR(i, N) f[i] -= g[i];
  f = X.log(f);
  f[0] += 1;
  f = X.pow(f, K);
  print(X.diff(f));
}

int main() {
  Yorisou();
  return 0;
}