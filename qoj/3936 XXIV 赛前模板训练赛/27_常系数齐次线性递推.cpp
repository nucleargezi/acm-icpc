#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fps.hpp"
#include "YRS/poly/coef_of_rationals.hpp"

using mint = M99;
using fps = vc<mint>;
fps_t<mint> X;
void Yorisou() {
  INT(N, K);
  fps a(N), f(N);
  IN(a, f);
  for (Z &x : f) x = -x;
  f.insert(bg(f), 1);
  a = X.conv(a, f);
  sh(a, N);
  print(X.coef_of_rationals(a, f, K));
}

int main() {
  Yorisou();
  return 0;
}