#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/det_poly.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  vc<vc<mint>> a(N, vc<mint>(N)), b(a);
  IN(a, b);
  print(det_poly(a, b));
}

int main() {
  Yorisou();
  return 0;
}