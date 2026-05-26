#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps_pow.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, M);
  fps f(N * M + 1);
  FOR(i, M + 1) f[i] = X.C(M, i) * X.fac(M) * X.ifac(M - i);
  f = X.pow(f, N);
  mint s;
  FOR(i, N * M + 1) {
    mint ad = f[i] * X.fac(N * M - i);
    if (i & 1) s -= ad;
    else s += ad;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}